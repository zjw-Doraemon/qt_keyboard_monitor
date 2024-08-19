#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <keyboard_monitor.h>
#include <QFile.h>
#include <QMessageBox>
QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_start_monitor_clicked();

    void on_stop_monitor_clicked();

    void show_key(std::string);



private:
    Ui::MainWindow *ui;
    keyboard_monitor hook;
    QString path = "../../record_keyboard/record.txt";
};
#endif // MAINWINDOW_H
