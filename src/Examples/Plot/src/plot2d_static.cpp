// Qt5 //
#include <QApplication>
// Eigen //
#include <Eigen/Core>
// STL //
#include <vector>
// Plot //
#include <plot.h>

int main(int argc, char** argv)
{
  using namespace CppRobotics;
  using namespace std;
  
  // need to initialize Qt //
  QApplication app(argc, argv);

  // 2d plotting //
  Plot2D plt;

  vector<QColor> color {
    QColor(255,0,0),
    QColor(0,255,0),
    QColor(0,0,255)};

  // add points //
  for(uint i=0; i<10; i++) {
    plt.addGraph(Plot2D::GraphType::Point);
    plt.setColor(i,color[i%3]);
    plt.setSize(i,static_cast<double>((i+1)*5));
    Eigen::Vector2d p = 10000.0*Eigen::Vector2d::Random();
    plt.addPoint(i, p);
  }
  // show the plot //
  plt.showPlot();

  // app.exec() creates the loop for qt gui //
  return app.exec();
}
