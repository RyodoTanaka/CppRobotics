#include <plot.h>
#include <ui_2dplot.h>
#include <algorithm>

namespace CppRobotics {
Plot2D::Plot2D(QWidget *parent) :
QMainWindow(parent),
ui_(new Ui::Plot2D)
{

  initialize();
}

Plot2D::~Plot2D()
{
  delete ui_;
}

void Plot2D::initialize()
{
  // Ui setup //
  ui_->setupUi(this);
  // Qt setup //
  ui_->plot->addGraph();
  ui_->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
  ui_->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
}

void Plot2D::plotPoint(const double& x, const double& y)
{
  x_.append(x);
  y_.append(y);
  x_min_ = std::min(x_min_, x);
  x_max_ = std::max(x_max_, x);
  y_min_ = std::min(y_min_, y);
  y_max_ = std::max(y_max_, y);
  qplot();
}

void Plot2D::plotPoint(const Eigen::Vector2d& p, const double& size, const QColor& color)
{
  x_.append(p.x());
  y_.append(p.y());
  x_min_ = std::min(x_min_, p.x());
  x_max_ = std::max(x_max_, p.x());
  y_min_ = std::min(y_min_, p.y());
  y_max_ = std::max(y_max_, p.y());
  auto ss = ui_->plot->graph(0)->scatterStyle();
  ss.setPen(QPen(color));
  ss.setBrush(color);
  ss.setSize(size);
  ui_->plot->graph(0)->setScatterStyle(ss);
  qplot();
}

void Plot2D::clearPoint(void)
{
  x_.clear();
  y_.clear();
  qplot();
}

void Plot2D::qplot(void)
{
  ui_->plot->xAxis->setRangeUpper(x_max_*1.2);
  ui_->plot->xAxis->setRangeLower(x_min_*1.2);
  ui_->plot->yAxis->setRangeUpper(y_max_*1.2);
  ui_->plot->yAxis->setRangeLower(y_min_*1.2);
  ui_->plot->graph(0)->addData(x_.back(), y_.back());
  // ui_->plot->replot();
  // ui_->plot->update();
}
} // namespace CppRobotics
