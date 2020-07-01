#ifndef PLOT_H
#define PLOT_H
// Qt //
#include <QMainWindow>
// Eigen //
#include <Eigen/Core>
#include <Eigen/Dense>
// STL //
#include <memory>

namespace CppRobotics {
namespace Ui {
class Plot2D;
}
class Plot2D : public QMainWindow
{
  Q_OBJECT

 public:
  enum GraphType {
    Point,
    Line,
    Circle,
    Elipse,
    Rectangle,
  };
  
  explicit Plot2D(QWidget *parent = 0);
  ~Plot2D();

  void addGraph(const GraphType& type);
  void removeGraph(void);
  void removeGraph(const uint& id);
  void clearGraph(void);
  void clearGraph(const uint& id);
  void showPlot(void);
  
  // setter //
  void addPoint(const uint& id, const double& x, const double& y);
  void addPoint(const uint& id, const Eigen::Vector2d& p);
  void setColor(const uint& id, const QColor& color);
  void setSize(const uint& id, const double& size);
  void plot(void);
                                                  
 private slots:
  
 private:
  // user interface //
  std::shared_ptr<Ui::Plot2D> ui_;
  struct Bound {
    Eigen::Vector2d min;
    Eigen::Vector2d max;
  };
  Bound bound_;
};
} // namespace CppRobotics

#endif // PLOT_H
