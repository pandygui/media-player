#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <dlabel.h>

DWIDGET_USE_NAMESPACE

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    TitleBar(QWidget *parent = 0);

    void setTitleText(QString &title);

private:
    QLabel *m_title;
};

#endif // TITLEBAR_H
