// Eigen //
#include <Eigen/Core>
// Qt5 //
#include <QApplication>
// Original //
#include <plot.h>

int main(int argc, char** argv)
{
  // need to initialize Qt //
  QApplication app(argc, argv);

  // 2d plotting //
  CppRobotics::Plot2D plt;

  for(uint i=0; i<10; i++) {
    Eigen::Vector2d p = 10.0*Eigen::Vector2d::Random();
    plt.plotPoint(p, 8, QColor(i*10,i*20,i*14));
  }
  Eigen::Vector2d p = 10.0*Eigen::Vector2d::Random();
  plt.plotPoint(p, 8, QColor(255,0,0));
  
  plt.show();
  
  return app.exec();
}
