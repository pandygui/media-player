#include <DApplication>
#include <DMainWindow>
#include <dutility.h>
#include <DTitlebar>
#include "mainwidget.h"
#include "titlebar.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();

    DApplication app(argc, argv);
    app.setTheme("light");
    app.setWindowIcon(QIcon(":/resources/icon.svg"));

    DMainWindow window;
    TitleBar *titlebar = new TitleBar();
    MainWidget *widget = new MainWidget();

    window.titleBar()->setCustomWidget(titlebar, Qt::AlignVCenter, false);
    window.setCentralWidget(widget);

    window.setMinimumSize(700, 500);
    window.show();

    DUtility::moveToCenter(&window);

    return app.exec();
}
