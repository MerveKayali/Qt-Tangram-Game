#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renk = qRgb(255,255,255);
    QImage ortam(600,500,QImage::Format_RGB32);
    ui->label->setPixmap(QPixmap::fromImage(ortam));
    res = ortam;
    QImage don(500,500,QImage::Format_RGB32);    
    donusum = ortam;
    ui->label->setGeometry(0,0,600,500);
    ui->label->setFrameShape(QFrame::Box);
    ui->label->show();
    QImage resim("C:/Users/merve/Desktop/tangram1.jpg");
    ui->label_3->setPixmap(QPixmap::fromImage(resim));
    resim1 = resim;
    ui->comboBox->addItems({"50","100","150"});




}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::CemberCizBresenham()
{
    int x =ui->lineEdit->text().toInt();
    int y = 0;
    int hata = 0;
    int hata1; // x,y+1
    int hata2; // x-1,y+1


    while(x>=y)
    {
        QApplication::processEvents();
        hata1 = hata+2*y+1;
        hata2=hata+(2*y+1)-(2*x-1);
        if(abs(hata1)<abs(hata2))
        {
            y++;
            hata = hata1;
        }
        else
        {
            x--;
            y++;
            hata = hata2;
        }
        SimetriBul(x,y);
        ui->label->setPixmap(QPixmap::fromImage(res));
    }
    //doldur(ilkNokta.x(),ilkNokta.y(),res.pixel(ilkNokta.x(),ilkNokta.y()),renk);
}
void MainWindow::SimetriBul(int x, int y)
{
    res.setPixel(ilkNokta.x()+x,ilkNokta.y()+y,renk);
    res.setPixel(ilkNokta.x()+x,ilkNokta.y()-y,renk);
    res.setPixel(ilkNokta.x()+y,ilkNokta.y()+x,renk);
    res.setPixel(ilkNokta.x()-y,ilkNokta.y()+x,renk);
    res.setPixel(ilkNokta.x()-x,ilkNokta.y()+y,renk);
    res.setPixel(ilkNokta.x()-x,ilkNokta.y()-y,renk);
    res.setPixel(ilkNokta.x()-y,ilkNokta.y()-x,renk);
    res.setPixel(ilkNokta.x()+y,ilkNokta.y()-x,renk);

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    ilkNokta = event->pos();
    Koseler.append(event->pos());
    CemberCizBresenham();
}




void MainWindow::doldur(int x, int y, QRgb zemin, QRgb yeniRenk)
{
    QApplication::processEvents();
    if(res.pixel(x,y)==zemin)
    {
        res.setPixel(x,y,yeniRenk);
        ui->label->setPixmap(QPixmap::fromImage(res));
        doldur(x+1,y,zemin,yeniRenk);
        doldur(x-1,y,zemin,yeniRenk);
        doldur(x,y+1,zemin,yeniRenk);
        doldur(x,y-1,zemin,yeniRenk);
    }
}

void MainWindow::DogruCizDDA2(QPoint ilk, QPoint son)
{
    double dx=son.x()-ilk.x();
    double dy=son.y()-ilk.y();
    double Xartim, Yartim;
    double adim;
    double x,y;
    if(fabs(dx)>fabs(dy))
    {
        adim=fabs(dx);
    }
    else
    {
        adim=fabs(dy);
    }
    Xartim=dx/adim;
    Yartim=dy/adim;
    x=ilk.x();
    y=ilk.y();

    for(int i=0; i<adim; i++)
    {
        QApplication::processEvents();
        x+=Xartim;
        y+=Yartim;
        res.setPixel(round(x),round(y),renk);
        ui->label->setPixmap(QPixmap::fromImage(res));
    }

}

void MainWindow::on_pushButton_clicked()
{
    Koseler.append(Koseler[0]);
    for(int i=0; i<Koseler.length()-1; i++)
    {
        DogruCizDDA2(Koseler[i],Koseler[i+1]);
    }
    Koseler.clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    doldur(ilkNokta.x(),ilkNokta.y(),res.pixel(ilkNokta.x(),ilkNokta.y()),renk);
}

void MainWindow::on_actionOlceklendir_triggered()
{
    double x,y;
    double sx,sy;
    sx = 1.5;
    sy = 1.5;

    for(int i = 0; i<res.width();i++)
    {
        for(int j = 0 ; j<res.height();j++)
        {
            x = i*sx;
            y = j*sy;
            donusum.setPixel(x,y,res.pixel(i,j));
        }
        ui->label->setPixmap(QPixmap::fromImage(donusum));

    }
}


void MainWindow::on_actionOtele_triggered()
{
    int iboyut=ui->comboBox->currentText().toInt();
    int jboyut=ui->comboBox->currentText().toInt();

    for(int i = 0; i<res.width();i++)
    {
        for(int j = 0 ; j<res.height();j++)
        {
            donusum.setPixel(i+iboyut,j+jboyut,res.pixel(i,j));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(donusum));
}



void MainWindow::on_pushButton_3_clicked()
{

    QImage resim("C:/Users/merve/Desktop/tangram2.jpg");
    ui->label_3->setPixmap(QPixmap::fromImage(resim));
    resim1 = resim;

}


void MainWindow::on_pushButton_4_clicked()
{
    QImage resim("C:/Users/merve/Desktop/tangram1.jpg");
    ui->label_3->setPixmap(QPixmap::fromImage(resim));
    resim1 = resim;
}

