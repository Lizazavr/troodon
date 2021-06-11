#include <QCoreApplication>
#include <QPainter>
#include <QTimer>
#include <QFontMetrics>
#include "fairy.h"
#include "Random.h"

Fairy::Fairy(QWidget *parent) : QWidget(parent) {

    setStyleSheet("background-color:black;");
    resize(B_WIDTH, B_HEIGHT);
    firstGame();
    level=1;
    }

void Fairy::firstGame(){
    inGame = true;
    click=0;
    timer=0;
    over=0;
    loadImages();
    initGame();

}

//загружаем изображения
void Fairy::loadImages() {

    pick1.load("C:/Users/ACER PC User/Documents/gameFairy/pick/fairy1.png");
    pick2.load("C:/Users/ACER PC User/Documents/gameFairy/pick/fairy2.png");
    pick3.load("C:/Users/ACER PC User/Documents/gameFairy/pick/fairy3.png");
    pick6.load("C:/Users/ACER PC User/Documents/gameFairy/pick/fairy4.png");
    pick7.load("C:/Users/ACER PC User/Documents/gameFairy/pick/fairy5.png");
    pick5.load("C:/Users/ACER PC User/Documents/gameFairy/pick/forest.png");
}

//
void Fairy::initGame() {

    inGame = true;
    locateFairy();
    timerId = startTimer(DELAY);
}


void Fairy::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    doDrawing();
}

//отрисовка изображений
void Fairy::doDrawing() {

    timer++;
    QPainter qp(this);

    if ((inGame==1)&&(timer<=240)) {
        qp.drawImage(pick5_x, pick5_y, pick5);
        qp.drawImage(pick1_x, pick1_y, pick1);
        qp.drawImage(pick2_x, pick2_y, pick2);
        qp.drawImage(pick3_x, pick3_y, pick3);
        qp.drawImage(pick4_x, pick4_y, pick4);
        qp.drawImage(pick6_x, pick6_y, pick6);
        qp.drawImage(pick7_x, pick7_y, pick7);

        QPainter qp3(this);
        messageTimer(qp3);

    } else {
        gameOver(qp);
        over=1;
    }
}

//конец уровня, вывод сообщений
void Fairy::gameOver(QPainter &qp) {

    QString message = "Game over! Click to start a new game";
    QFont font("Courier", 15, QFont::DemiBold);
    int textWidth = 400;
    qp.setPen(QColor(Qt::white));
    qp.setFont(font);
    int h = height();
    int w = width();
    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, message);
    QPainter qp1(this);
    messageClick(qp1);
}

void Fairy::messageClick(QPainter &qp1) {

    QString s = QString::number(click);
    QString s1 = QString::number(level);
    QString message = "Level: " + s1 + " You click:  " + s;
    QFont font1("Courier", 15, QFont::DemiBold);
    int textWidth = 400;
    qp1.setPen(QColor(Qt::white));
    qp1.setFont(font1);
    int h = height();
    int w = width();
    qp1.translate(QPoint(w/2, (2*h)/3));
    qp1.drawText(-textWidth/2, 0, message);
}

//уровень во время игры, отображение
void Fairy::messageTimer(QPainter &qp3) {

    QString s2 = QString::number(level);
    QString message3 = "Level:  " + s2;
    QFont font3("Courier", 15, QFont::DemiBold);
    int textWidth3 = 400;
    qp3.setPen(QColor(Qt::white));
    qp3.setFont(font3);
    int h3 = height();
    int w3 = width();
    qp3.translate(QPoint(h3/4, w3/20));
    qp3.drawText(-textWidth3/2, 0, message3);
}

void Fairy::checkCollision() {

    if(!inGame) {
        killTimer(timerId);
    }
}

//местоположение фей
void Fairy::locateFairy() {

    pick5_x = 1;
    pick5_y = 1;

    //изображение феи на которую нужно будет нажимать
    random_number = Random::get(1, 5);
    if(random_number == 1){
    pick4.load("C:/Users/ACER PC User/Documents/gameFairy/pick/fairy1_2.png");}
    else if(random_number == 2){
    pick4.load("C:/Users/ACER PC User/Documents/gameFairy/pick/fairy2_2.png");}
    else if(random_number == 3){
    pick4.load("C:/Users/ACER PC User/Documents/gameFairy/pick/fairy3_2.png");}
    else if(random_number == 4){
    pick4.load("C:/Users/ACER PC User/Documents/gameFairy/pick/fairy4_2.png");}
    else {
    pick4.load("C:/Users/ACER PC User/Documents/gameFairy/pick/fairy5_2.png");}


    pick4_x = 325;
    pick4_y = 1;

    pick1_x = Random::get(10, 550);
    pick1_y = Random::get(150, 550);

    pick2_x = Random::get(10, 550);
    pick2_y = Random::get(150, 550);

    pick3_x = Random::get(10, 550);
    pick3_y = Random::get(150, 550);

    pick6_x = Random::get(10, 550);
    pick6_y = Random::get(150, 550);


    pick7_x = Random::get(10, 550);
    pick7_y = Random::get(150, 550);

}


//
void Fairy::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);
    if (inGame) {
        checkCollision();
    }
    repaint();
}

//считываем нажатия мышки
void Fairy::mousePressEvent ( QMouseEvent *event ){

    int x1=event->x();
    int y1=event->y();

    //если время закончилось
    if(over==1){
    if((x1 >1)&&(x1 < 800)&&(y1>1)&&(y1<800)){
        inGame=true;
        level++;
        firstGame();
    }
   }

    //обрабатываем нажатие на нужное изображение
    if(random_number == 1){
    if((x1 >=(pick1_x + 30))&&(x1 <=(pick1_x + 160))&&(y1>=(pick1_y + 30))&&(y1<=(pick1_y + 200))){
        click++;
        locateFairy();
    }
        }else if(random_number == 2){
            if((x1 >=(pick2_x + 30))&&(x1 <=(pick2_x + 130))&&(y1>=(pick2_y + 30))&&(y1<=(pick2_y + 200))){
                click++;
                locateFairy();
            }
    }else if(random_number == 3){
                if((x1 >=(pick3_x + 30))&&(x1 <=(pick3_x + 130))&&(y1>=(pick3_y + 30))&&(y1<=(pick3_y + 200))){
                    click++;
                    locateFairy();
                }
        }else if(random_number == 4){
                    if((x1 >=(pick6_x + 30))&&(x1 <=(pick6_x + 136))&&(y1>=(pick6_y + 30))&&(y1<=(pick6_y + 170))){
                        click++;
                        locateFairy();}
            }else if(random_number == 5){
            if((x1 >=(pick7_x + 30))&&(x1 <=(pick7_x + 130))&&(y1>=(pick7_y + 30))&&(y1<=(pick7_y + 200))){
                click++;
                locateFairy();
            }
    }
}






