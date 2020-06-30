#ifndef PLOT_H
#define PLOT_H
// Qt //
#include <QMainWindow>
// Eigen //
#include <Eigen/Core>
#include <Eigen/Dense>
// STL //
#include <limits>

namespace CppRobotics {
namespace Ui {
class Plot2D;
}

class Plot2D : public QMainWindow
{
  Q_OBJECT

 public:
  explicit Plot2D(QWidget *parent = 0);
  ~Plot2D();

  void plotPoint(const double& x, const double& y);
  void plotPoint(const Eigen::Vector2d& p);
  void clearPoint(void);
 private slots:
  void initialize(void);  
  void qplot(void);
 private:
  Ui::Plot2D *ui_;
  QVector<double> x_;
  QVector<double> y_;
  double x_min_{-5};
  double x_max_{5};
  double y_min_{-5};
  double y_max_{5};
};
} // namespace CppRobotics

#endif // PLOT_H
