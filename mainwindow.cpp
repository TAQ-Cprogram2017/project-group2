#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player=new QMediaPlayer(this);

    playlist = new QMediaPlaylist;
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    playlist->addMedia(QUrl("C://Music//14.mp3"));
    playlist->addMedia(QUrl("C://Music//13.mp3"));
    playlist->setCurrentIndex(2);
    player = new QMediaPlayer(this);
    player->setPlaylist(playlist);
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    this->close() ;
}

void MainWindow::on_pushButton_clicked()
{

    game* shudo=new game ;


    shudo->show();


}
