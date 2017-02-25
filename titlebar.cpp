#include "titlebar.h"
#include <QLabel>

TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    QLabel *m_icon = new QLabel;
    m_icon->setPixmap(QPixmap(":/resources/icon.svg").scaled(24, 24));

    m_title = new QLabel("engine-player");
    m_title->setAlignment(Qt::AlignHCenter);

    layout->addWidget(m_icon);
    layout->addStretch();
    layout->addWidget(m_title);
    layout->addStretch();
}

void TitleBar::setTitleText(QString &title)
{
    m_title->setText(title);
}
