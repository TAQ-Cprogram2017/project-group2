#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{

    ui->setupUi(this);
    QPixmap pix(":/one.png") ;

     this->setWindowTitle("shuDO Game");
     //this->setWindowIcon(QIcon(pixmap,100,100));
    this->setFixedWidth(1000);//画窗口
    this->setFixedHeight(900);

   /* for(int i=0;i<=8;i++)
    {
        for(int j=0 ;j<=8;j++)
        {
        shudu[i][j]=new QPushButton(this) ;
        shudu[i][j]->setIcon(QIcon(pix));

        shudu[i][j]->setIconSize(*buttonsize);

        shudu[i][j]->setGeometry((i*100),(j*100),100,100);

        }

     }*/
    ifstream read("C:\\Users\\27254\\Desktop\\ShuDu.txt")	;
    srand((unsigned)time(0));
        int i=rand()%5 ; //随机选取种子矩阵
        int line=0 ;
        if(i>0)
        {
            line=i*9 ;
        }
        //cout<<i<<endl ;
        int count=1 ;
        char tempstring[20] ;
        char storenumber[20] ;
        while(count<=line)
        {
            read.getline(tempstring,20) ;
            count=count+1 ;
        }
        for(int m=0;m<=8;m++)
        {
            read.getline(storenumber,20) ;//读入一行
            //cout<<storenumber<<endl ;
            for(int j=0;j<=8;j++)
            {
            this->SudoKu[m][j]=int(storenumber[j*2]-'0') ;
            }

        }
        srand((unsigned)time(0));

            exchangenumber(this->SudoKu,(rand()%8)+1,(rand()%8)+1) ;
            exchangenumber(this->SudoKu,(rand()%8)+1,(rand()%8)+1)  ;
            exchangenumber(this->SudoKu,(rand()%8)+1,(rand()%8)+1)  ;
            exchangenumber(this->SudoKu,(rand()%8)+1,(rand()%8)+1)   ;
            exchangenumber(this->SudoKu,(rand()%8)+1,(rand()%8)+1)    ;
            for(int i=0;i<=8;i++)
            {
                for(int j=0;j<=8;j++)
                    {
                    cout<<SudoKu[i][j]<<" " ;

                    }
                   cout<<endl ;

            }
            this->removenumber(this->SudoKu,67);//挖空
            for(int m=0;m<=8;m++)
            {
                for(int n=0;n<=8;n++)
                {
                    if(SudoKu[m][n]!=10)
                    {
                        this->flag[m][n]=1 ;//一开始有的设置标志位为1
                    }
                }
            }
            //
                Box=new QComboBox(this) ;//下拉菜单
            Box->addItem(QWidget::tr("1"));
            Box->addItem(QWidget::tr("2"));
            Box->addItem(QWidget::tr("3"));
            Box->addItem(QWidget::tr("4"));
            Box->addItem(QWidget::tr("5"));
            Box->addItem(QWidget::tr("6"));
            Box->addItem(QWidget::tr("7"));
            Box->addItem(QWidget::tr("8"));
            Box->addItem(QWidget::tr("9"));
            boxnumber=0 ;
            Box->setVisible(false);
            doingx1=0 ;
            doingy1=0 ;
            connect(Box, SIGNAL(currentIndexChanged(int)), this, SLOT(boxChange()));


}

bool game::check(int a[9][9])//检查是否正确
{
        bool result = true;
        for (int j1 = 0; j1 <= 8; j1++)
        {
            for (int m1 = 0; m1 <= 8; m1++)
            {
                int temp = 0;
                temp = a[j1][m1];
                //
                if (temp >= 1 && temp <= 9)
                {
                    for (int u1 = 0; u1 <=m1-1; u1++)
                    {
                        if (temp == a[j1][u1])
                        {
                            result = false;
                            return result;
                        }
                    }
                    for (int u2 =m1+1; u2 <=8; u2++)
                    {
                        if (temp == a[j1][u2])
                        {
                            result = false;
                            return result;
                        }
                    }
                    for (int y1 = 0; y1 <= j1-1; y1++)
                    {
                        if (temp == a[y1][m1])
                        {
                            result = false;
                            return result;
                        }
                    }
                    for (int y2 = j1+1; y2 <= 8; y2++)
                    {
                        if (temp == a[y2][m1])
                        {
                            result = false;
                            return result;
                        }
                    }
                }
            }

        }
        return result;
}

void game::exchangenumber(int m[9][9],int x,int y)
{
    int place1=0 ;
    int place2=0 ;
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=8;j++)
        {
            if(m[i][j]==x)
            {
                place1=j ;
            }
            if(m[i][j]==y)
            {
                place2=j ;
            }
        }
        int temp=m[i][place1] ;
        m[i][place1]=m[i][place2] ;
        m[i][place2]=temp ;
    }
}
void game::removenumber(int Math[9][9],int number)
{
    srand((unsigned)time(0));
    int beginnumber[200] ;
        for (int i = 0; i <= (number*2)-1; i++)
        {

            beginnumber[i]=rand()%9;

        }

        int p1=0 ;
        for (int t = 1; t <= number; t++)
        {

            Math[beginnumber[p1]][beginnumber[p1 + 1]]=10;
            p1 = p1 + 2;

        }
}
void game::paintEvent(QPaintEvent *event)//把数改成图
{
    Q_UNUSED(event);


       QPainter painter(this);
       for (int i=0; i<9; i++)
       {
           for (int j=0;j<9;j++)
         {
         if(this->SudoKu[i][j]==1)
         {
          painter.drawPixmap(0+100*j,0+100*i,100,100,QPixmap(":/one.png"));
         }
         if(this->SudoKu[i][j]==2)
         {
          painter.drawPixmap(0+100*j,0+100*i,100,100,QPixmap(":/two.png"));
         }
         if(this->SudoKu[i][j]==3)
         {
          painter.drawPixmap(0+100*j,0+100*i,100,100,QPixmap(":/three.png"));
         }
         if(this->SudoKu[i][j]==4)
         {
          painter.drawPixmap(0+100*j,0+100*i,100,100,QPixmap(":/four.png"));
         }
         if(this->SudoKu[i][j]==5)
         {
          painter.drawPixmap(0+100*j,0+100*i,100,100,QPixmap(":/five.png"));
         }
         if(this->SudoKu[i][j]==6)
         {
          painter.drawPixmap(0+100*j,0+100*i,100,100,QPixmap(":/six.png"));
         }
         if(this->SudoKu[i][j]==7)
         {
          painter.drawPixmap(0+100*j,0+100*i,100,100,QPixmap(":/seven.png"));
         }
         if(this->SudoKu[i][j]==8)
         {
          painter.drawPixmap(0+100*j,0+100*i,100,100,QPixmap(":/eight.png"));
         }
         if(this->SudoKu[i][j]==9)
         {
          painter.drawPixmap(0+100*j,0+100*i,100,100,QPixmap(":/nine.png"));
         }
         if(this->SudoKu[i][j]==10)
         {
          painter.drawPixmap(0+100*j,0+100*i,100,100,QPixmap(":/zero.png"));
         }
         }
       }

}

game::~game()
{
    delete ui;
}

void game::boxChange()//下拉菜单
{
    if(flag[doingy1][doingx1]==1)
    {
      Box->setVisible(false);
     }
    else
     {
     int temp=SudoKu[doingy1][doingx1] ;//获取当前选择的数字
     this->SudoKu[doingy1][doingx1]=(Box->currentIndex()+1) ;
     if(check(SudoKu)==false)
     {
         QMessageBox::information(this, "Wrong warning", "Your behaviour is wrong!", QMessageBox::Ok);
         SudoKu[doingy1][doingx1]=temp ;
          this->update();
     }
     if(check(SudoKu)==true)
     {
         this->update();
     }
     this->Box->setVisible(false);
     }

}

void game::mousePressEvent(QMouseEvent* placelocation)//鼠标点击事件
{
     QPoint *point=new QPoint() ;
     *point=placelocation->pos() ;
      int x1=point->x() ;
      int y1=point->y(); //获取鼠标点击时鼠标的坐标
      doingx1=(x1/100) ;
      doingy1=(y1/100) ;//得到数独数组x,y的坐标，即suduku[y1][x1]

        this->Box->setGeometry(100*(doingx1+1),50+100*(doingy1),100,20);
        this->Box->setVisible(true);
}

