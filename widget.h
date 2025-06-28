#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QDebug>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QTimer>
#include <QDialog>
#include <QHostAddress>
#include <QMessageBox>
#include <QAudioDevice>
#include <QMediaDevices>
#include <QCoreApplication>
#include <QEventLoop>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_searchButton_clicked();

    void searchWidget(const QString &query);

    void videoPlayer(const QString &path);

    void checkAudioDevice();

private:
    Ui::Widget *ui;

    QTimer *deviceCheckTimer;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QAudioOutput *audioOutput;
    QAudioDevice currentAudioDevice;


};
#endif // WIDGET_H

