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

    void setTitleText(const QString &title);
    void setFileName(const QString &name);

private:
    DLabel *m_title;
    DLabel *m_file_name;
};

#endif // TITLEBAR_H
