#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"game.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots://菜单按钮


    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlaylist*  playlist;
    QMediaPlayer* player;

};


#endif // MAINWINDOW_H
