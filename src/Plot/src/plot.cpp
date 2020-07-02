#include <plot.h>
#include <ui_2dplot.h>
#include <algorithm>

namespace CppRobotics {
Plot2D::Plot2D(QWidget *parent) : QMainWindow(parent) {
  // setup ui //
  ui_ = std::make_shared<Ui::Plot2D>();
  ui_->setupUi(this);
  // set default bounds //
  bound_.max.x() = 5;
  bound_.max.y() = 5;
  bound_.min.x() = -5;
  bound_.min.y() = 5;
}

Plot2D::~Plot2D() {
  ui_.reset();
}

void Plot2D::plot(void) {
  // set figure range by bounds //
  ui_->plot->xAxis->setRangeUpper(bound_.max.x()*1.2);
  ui_->plot->xAxis->setRangeLower(bound_.min.x()*1.2);
  ui_->plot->yAxis->setRangeUpper(bound_.max.y()*1.2);
  ui_->plot->yAxis->setRangeLower(bound_.min.y()*1.2);
  // plot //
  ui_->plot->replot();
  ui_->plot->update();
}

void Plot2D::addGraph(const Plot2D::GraphType& type) {
  ui_->plot->addGraph();
  uint id = ui_->plot->graphCount() - 1;
  switch(type) {
    case Plot2D::GraphType::Point : {
      ui_->plot->graph(id)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
      break;
    }
    default:
      break;
  };
}

void Plot2D::removeGraph(void) {
  ui_->plot->clearGraphs();
}

void Plot2D::removeGraph(const uint& id) {
  ui_->plot->removeGraph(id);
}

void Plot2D::clearGraph(void) {
  QVector<double> x;
  QVector<double> y;
  for(uint i=0; i<ui_->plot->graphCount(); i++)
    ui_->plot->graph(i)->setData(x,y);
}

void Plot2D::clearGraph(const uint& id) {
  QVector<double> x;
  QVector<double> y;
  ui_->plot->graph(id)->setData(x,y);
}

void Plot2D::showPlot(void) {
  plot();
  show();
  QApplication::quit();  
}

void Plot2D::addPoint(const uint& id, const double& x, const double& y) {
  // set bounds //
  bound_.min.x() = std::min(bound_.min.x(), x);
  bound_.min.y() = std::min(bound_.min.y(), y);
  bound_.max.x() = std::max(bound_.max.x(), x);
  bound_.max.y() = std::max(bound_.max.y(), y);
  // add point data //
  ui_->plot->graph(id)->addData(x, y);
}

void Plot2D::addPoint(const uint& id, const Eigen::Vector2d& p) {
  // set bounds //
  bound_.min.x() = std::min(bound_.min.x(), p.x());
  bound_.min.y() = std::min(bound_.min.y(), p.y());
  bound_.max.x() = std::max(bound_.max.x(), p.x());
  bound_.max.y() = std::max(bound_.max.y(), p.y());
  // add point data //
  ui_->plot->graph(id)->addData(p.x(), p.y());
}

void Plot2D::setColor(const uint& id, const QColor& color) {
  auto ss = ui_->plot->graph(id)->scatterStyle();
  ss.setPen(QPen(color));
  ss.setBrush(color);
  ui_->plot->graph(id)->setScatterStyle(ss);
}

void Plot2D::setSize(const uint& id, const double& size) {
  auto ss = ui_->plot->graph(id)->scatterStyle();
  ss.setSize(size);
  ui_->plot->graph(id)->setScatterStyle(ss);

}

} // namespace CppRobotics
