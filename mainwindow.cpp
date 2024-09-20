#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // 传递键值信息
    connect(&hook,&keyboard_monitor::send_message,this,&MainWindow::show_key);



    this->setWindowIcon(QIcon(":/resource/keyboard.png"));
    ui->textEdit->setStyleSheet("QTextEdit { font-family: 'Arial'; font-size: 16pt; font-weight: bold; }");
    ui->textEdit->setReadOnly(true);

    //设置托盘图标
    create_tray_icon();





}


MainWindow::~MainWindow()
{
    delete trayIcon;
    trayIcon=nullptr ;
    trayMenu=nullptr;

    showAction=nullptr;
    exitAction=nullptr;
    delete ui;
}



// 创建缩小图标
void MainWindow::create_tray_icon(){

    trayIcon=new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/resource/keyboard.png"));
    QMenu *trayMenu = new QMenu(this);
    // 添加动作
    QAction *showAction = new QAction("显示应用", this);
    QAction *exitAction = new QAction("退出", this);
    QAction *startAction = new QAction("开机自启",this);
    // 托盘信号
    connect(showAction, &QAction::triggered, this, [this](){
        this->show();
    });
    connect(exitAction, &QAction::triggered, this, &QApplication::quit);

    trayMenu->addAction(showAction);
    trayMenu->addSeparator();  // 添加分隔符
    trayMenu->addAction(exitAction);
    trayMenu->addAction(startAction);


    // 将菜单添加到托盘图标中
    trayIcon->setContextMenu(trayMenu);

    // 显示托盘图标
    trayIcon->show();
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        qDebug() << "系统不支持托盘图标";
        return;
    }

}


//重载关闭函数
void MainWindow::closeEvent(QCloseEvent *event) {
    this->hide();  // 隐藏窗口
    event->ignore();  // 忽略关闭事件，防止应用程序退出



}



void MainWindow::on_start_monitor_clicked()
{

    hook.start();
    ui->start_monitor->setEnabled(false);
    ui->start_monitor->setStyleSheet
    ("QPushButton { background-color: gray; color: white; }"); // 改变按钮的样式
    ui->stop_monitor->setEnabled(true);
    ui->stop_monitor->setStyleSheet(""); // 恢复按钮的默认样式


}


void MainWindow::on_stop_monitor_clicked()
{
    hook.stop();
    ui->start_monitor->setEnabled(true);
    ui->start_monitor->setStyleSheet(""); // 恢复按钮的默认样式
    ui->stop_monitor->setEnabled(false);
    ui->stop_monitor->setStyleSheet
    ("QPushButton { background-color: gray; color: white; }"); // 改变按钮的样式

}

void MainWindow::show_key(std::string a){
    ui->textEdit->append(QString::fromStdString(a));
}
