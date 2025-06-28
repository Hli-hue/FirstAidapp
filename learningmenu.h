#ifndef LEARNINGMENU_H
#define LEARNINGMENU_H

#include <QMainWindow>
#include <QSignalMapper>
#include <QTextEdit>
#include <QAction>
#include <QFile>
#include <QMessageBox>
#include <QMap>
#include <QVector>

namespace Ui {
class LearingMenu;
}

class LearingMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit LearingMenu(QWidget *parent = nullptr);
    ~LearingMenu();

private slots:

    void on_action0_triggered();

    void on_action1_triggered();

    void on_action2_triggered();

    void on_action3_triggered();

    void on_action4_triggered();

    void on_action5_triggered();

    void on_action6_triggered();

    void on_action7_triggered();

    void on_action8_triggered();

    void on_action9_triggered();

    void on_action10_triggered();

    void on_action11_triggered();

    void on_action12_triggered();

    void on_action13_triggered();

    void on_action14_triggered();

    void on_action15_triggered();

    void on_action16_triggered();

    void on_action17_triggered();

    void on_action18_triggered();

    void on_action19_triggered();

    void on_action20_triggered();

    void on_action21_triggered();

    void on_action22_triggered();

    void on_action23_triggered();

    void on_action24_triggered();

    void on_action25_triggered();

    void on_action26_triggered();

    void on_action_B_triggered();

private:
    Ui::LearingMenu *ui;
    QString readFileContent(const QString &filePath);
};

#endif // LEARNINGMENU_H
