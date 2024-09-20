#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <keyboard_monitor.h>
#include <QFile.h>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDir>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QMenu>

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


public slots:
    void on_start_monitor_clicked();

    void on_stop_monitor_clicked();

    void show_key(std::string);

    void closeEvent(QCloseEvent *event) override;

    void create_tray_icon();

private:


    Ui::MainWindow *ui;

    keyboard_monitor hook;
    QSystemTrayIcon *trayIcon ;
    QMenu *trayMenu;
    // 列表图标
    QAction *showAction;
    QAction *exitAction;
    QAction *startAction;



};
#endif // MAINWINDOW_H
