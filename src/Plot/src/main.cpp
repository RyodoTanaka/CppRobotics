#include <plot.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CppRobotics::Plot2D plt;
    plt.show();

    return a.exec();
}
