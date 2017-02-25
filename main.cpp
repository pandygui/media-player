#include <DApplication>
#include <dutility.h>
#include "mainwindow.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();

    DApplication app(argc, argv);
    app.setTheme("dark");
    app.setWindowIcon(QIcon(":/resources/icon.svg"));

    MainWindow window;

    window.setWindowTitle("engine-player");

    window.setMinimumSize(700, 500);
    window.show();

    DUtility::moveToCenter(&window);

    return app.exec();
}
