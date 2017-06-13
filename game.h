#ifndef GAME_H
#define GAME_H
#include<iomanip>
#include<process.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
#include <QWidget>
#include <QApplication>
#include <QTime>
#include <QSplashScreen>
#include <QDebug>
#include <QElapsedTimer>
#include <QDateTime>
#include<QPushButton>
#include <qicon.h>
#include<qsize.h>
#include<qevent.h>
#include<qpoint.h>
#include<iostream>
#include<qpixmap.h>
#include <QMediaPlayer>
#include<QMediaPlaylist>
#include<QUrl>
#include<QVideoWidget>
#include<ctime>
#include<Qpainter>
#include<QComboBox>
#include <QtGui>
#include <QMessageBox>
using namespace std ;
namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();
    QPushButton *shudu[9][9] ;
    void mousePressEvent(QMouseEvent* placelocation);
    void removenumber(int Math[9][9],int number) ;
    void exchangenumber(int m[9][9],int x,int y) ;
    bool check(int a[9][9]) ;
    bool full(int h[9][9]) ;
   void game::paintEvent(QPaintEvent *event);
   void boxChange(int j) ;

public slots:
   void boxChange();
private:
    Ui::game *ui;
    int SudoKu[9][9] ;
    int boxnumber ;
    QComboBox* Box ;
    int doingx1 ;
    int doingy1 ;
    int flag[9][9] ;

};


#endif // GAME_H
