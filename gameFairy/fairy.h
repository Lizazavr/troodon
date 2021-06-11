#pragma once
#include <QTimer>
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>

class Fairy : public QWidget {

  public:
      Fairy(QWidget *parent = 0);

  protected:
      void paintEvent(QPaintEvent *);
      void timerEvent(QTimerEvent *);
      void mousePressEvent (QMouseEvent *event );
      static int randomBetween(int, int);

  private:
      QImage pick1;
      QImage pick2;
      QImage pick3;
      QImage pick4;
      QImage pick5;
      QImage pick6;
      QImage pick7;

      static const int B_WIDTH = 800; //ширина поля
      static const int B_HEIGHT = 800; //высота поля
      static const int DELAY = 140;

      int timerId;
      int pick1_x;
      int pick1_y;
      int pick2_x;
      int pick2_y;
      int pick3_x;
      int pick3_y;
      int pick4_x;
      int pick4_y;
      int pick5_x;
      int pick5_y;
      int pick6_x;
      int pick6_y;
      int pick7_x;
      int pick7_y;
      int random_number;
      int click;
      int level;
      int timer;
      int over;

      int x1();
      int y1();

      bool inGame;

      void firstGame();
      void loadImages();
      void initGame();
      void locateFairy();
      void checkCollision();
      void doDrawing();
      void gameOver(QPainter &);
      void messageClick(QPainter &);
      void messageTimer(QPainter &);

};



