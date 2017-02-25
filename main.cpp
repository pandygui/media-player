#include <DApplication>
#include <DMainWindow>
#include <dutility.h>
#include "mainwidget.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();

    DApplication app(argc, argv);
    app.setTheme("light");

    DMainWindow window;
    MainWidget *widget = new MainWidget();
    window.setCentralWidget(widget);


    window.setMinimumSize(700, 500);
    window.show();

    DUtility::moveToCenter(&window);

    return app.exec();
}
