#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_actionOlceklendir_triggered();

    void on_actionOtele_triggered();



    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QRgb renk;
    QPoint ilkNokta, sonNokta;
    QImage res;
    QImage donusum;
    QImage resim1;
    QList<QPoint> Koseler;
    void SimetriBul(int,int);
    void CemberCizBresenham();
    void DogruCizDDA2(QPoint ilk, QPoint son);
    void mousePressEvent(QMouseEvent*);
    void cemberBres();
    void simetriBul(int,int);
    void doldur(int,int,QRgb,QRgb);

};
#endif // MAINWINDOW_H
