#include <QApplication>
#include "fairy.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  Fairy window;

  window.setWindowTitle("Forest");
  window.show();

  return app.exec();
}
