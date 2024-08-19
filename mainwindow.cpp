#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&hook,&keyboard_monitor::send_message,this,&MainWindow::show_key);
    ui->textEdit->setStyleSheet("QTextEdit { font-family: 'Arial'; font-size: 16pt; font-weight: bold; }");
    ui->textEdit->setReadOnly(true);



}

MainWindow::~MainWindow()
{
    QString text = ui->textEdit->toPlainText();
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "Failed to open file:" << file.errorString();

    }
    else{
    QTextStream out(&file);
    out<<text;
    out<<"---------------------------------------------------------------------\n";
    qDebug()<<"信息写入文件成功";
    }

    delete ui;
}



void MainWindow::on_start_monitor_clicked()
{

    hook.start();
}


void MainWindow::on_stop_monitor_clicked()
{
    hook.stop();

}

void MainWindow::show_key(std::string a){
    ui->textEdit->append(QString::fromStdString(a));
}
