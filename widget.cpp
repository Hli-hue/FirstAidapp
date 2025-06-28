#include "widget.h"
#include "./ui_widget.h"
#include "EmergencyModel.h"
#include "searchengine.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_searchButton_clicked()
{
    //获取lineedit数据
    QString searchText=ui->lineEdit->text();

    //展示搜索界面
    searchWidget(searchText);

    ui->lineEdit->clear();

}

void Widget::searchWidget(const QString &query)
{
    //获取搜索结果
    EmergencyModel *e = new EmergencyModel;
    e->createJson();
    SearchEngine s(e->getJson());
    QJsonArray searchFinal=s.search(query);
    //检测qDebug()<<searchFinal;

    //创建滚动区域和容器
    QScrollArea * scrollArea= new QScrollArea(this);
    QWidget * container= new QWidget();
    QVBoxLayout * mainLayout= new QVBoxLayout(container);

    //动态生成显示器
    for(const QJsonValueConstRef &value: std::as_const(searchFinal)){
        QJsonObject obj=value.toObject();

        //创建带边框的容器
        QFrame * itemFrame = new QFrame(container);
        itemFrame->setFrameStyle(QFrame::Box);
        itemFrame->setStyleSheet("margin: 5px; padding: 8px;");

        //创建垂直布局
        QVBoxLayout* itemLayout= new QVBoxLayout(itemFrame);

        //添加字段内容
        for(const QString & key:obj.keys()){
            if(key!="video" && key!="keywords"){
                //QLabel *label= new QLabel(itemFrame);
                QJsonValue textValue=obj.value(key);
                QString displayContent;

                //修改
                if(textValue.isArray()){
                    //处理数组类型数据
                    QJsonArray textArray = textValue.toArray();
                    QStringList textItems;
                    for(const QJsonValue &item: textArray){
                        // 递归处理嵌套对象（可选）
                        if (item.isObject()) {
                            textItems << "{...}"; // 简化显示嵌套对象
                        } else {
                            textItems << item.toVariant().toString();
                        }
                    }
                    displayContent = QString("<b>%1:</b><ul><li>%2</li></ul>")
                                         .arg(key)
                                         .arg(textItems.join("</li><li>"));
                }else if(textValue.isObject()){
                    // 处理嵌套对象（可选）
                    displayContent = QString("<b>%1:</b> {...}").arg(key);
                }else{
                    // 处理普通类型
                    displayContent = QString("<b>%1:</b> %2")
                                         .arg(key)
                                         .arg(textValue.toVariant().toString());
                }

                //label->setText(QString("<b>%1:<b>%2").arg(key).arg(textString));
                QLabel *label = new QLabel(itemFrame);
                label->setText(displayContent);
                label->setWordWrap(true);
                label->setTextInteractionFlags(Qt::TextSelectableByMouse);
                //修改至此
                itemLayout->addWidget(label);

            }else if(key=="video"){
                QJsonValue textValue=obj.value(key);
                QString displayContent=textValue.toString();

                QLabel *label = new QLabel(itemFrame);
                label->setText("<a href='action://open_video/123' style='color: green;'>点击查看紧急救援指导视频</a> ");
                label->setTextFormat(Qt::RichText);
                label->setTextInteractionFlags(Qt::TextBrowserInteraction);
                label->setOpenExternalLinks(false); // 禁止自动打开外部链接

                connect(label, &QLabel::linkActivated, [displayContent, this, label](const QString &link) {
                    Q_UNUSED(link);
                    qDebug()<<"点击有效";
                    videoPlayer(displayContent);
                    label->setText("<span style='color: #666;'>已完成操作</span>");
                    label->setTextInteractionFlags(Qt::NoTextInteraction); // 可选禁用交互
                    // label->setTextInteractionFlags(Qt::NoTextInteraction); // 可选禁用交互
                });

                itemLayout->addWidget(label);

            }else{
                continue;
            }
        }

        //将项添加到主布局
        mainLayout->addWidget(itemFrame);

    }

    container->setLayout(mainLayout);
    scrollArea->setWidget(container);
    scrollArea->setWidgetResizable(true);

    QVBoxLayout *widgetLayout = new QVBoxLayout(this);
    widgetLayout->addWidget(scrollArea);
    setLayout(widgetLayout);
}





void Widget::videoPlayer(const QString &path){

    player = new QMediaPlayer;
    videoWidget = new QVideoWidget;
    audioOutput = new QAudioOutput;


    // 设置视频输出到 QVideoWidget
    player->setVideoOutput(videoWidget);
    player->setAudioOutput(audioOutput);

    // 加载视频文件并播放
    player->setSource(QUrl::fromLocalFile(path));
    audioOutput->setVolume(0.5);

    videoWidget->setAspectRatioMode(Qt::KeepAspectRatio);
    videoWidget->show();
    player->play();


    //videoWidget->resize(350,500);
    // 将 QVideoWidget 嵌入到 UI 中（例如布局中）
    layout()->addWidget(videoWidget);
    deviceCheckTimer = new QTimer(this);
    connect(deviceCheckTimer, &QTimer::timeout, this, &Widget::checkAudioDevice);
    deviceCheckTimer->start(1000);
}


void Widget::checkAudioDevice() {
    // 获取当前系统默认音频设备
    QAudioDevice defaultDevice = QMediaDevices::defaultAudioOutput();

    // 如果设备已变化
    if (defaultDevice != currentAudioDevice) {
        // 保存当前播放状态和进度
        bool isPlaying = (player->playbackState() == QMediaPlayer::PlayingState);
        qint64 position = player->position();

        // 停止播放并释放旧音频设备
        player->stop();
        delete audioOutput;

        // 创建新音频设备并绑定
        audioOutput = new QAudioOutput(defaultDevice, this);
        player->setAudioOutput(audioOutput);
        audioOutput->setVolume(0.5);  // 恢复音量

        // 更新当前设备信息
        currentAudioDevice = defaultDevice;

        // 恢复播放进度和状态
        player->setPosition(position);
        if (isPlaying) {
            player->play();
        }
    }
}
