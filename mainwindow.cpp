#include "mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : DMainWindow(parent)
{
    m_unit = 1000;
    open_file_name = "";

    m_player->setRenderer(renderer);

    connect(play_button, SIGNAL(clicked(bool)), this, SLOT(play_button_clicked()));
    connect(stop_button, SIGNAL(clicked(bool)), this, SLOT(stop_button_clicked()));

    connect(play_slider, SIGNAL(sliderMoved(int)), SLOT(seek_by_slider(int)));
    connect(play_slider, SIGNAL(sliderPressed()), SLOT(seek_by_slider()));
    connect(m_player, SIGNAL(positionChanged(qint64)), SLOT(update_slider(qint64)));
    connect(m_player, SIGNAL(started()), SLOT(update_slider()));
    connect(m_player, SIGNAL(notifyIntervalChanged()), SLOT(update_slider_unit()));

    initUI();
}

void MainWindow::initUI()
{
    titlebar->setFileName("");
    this->titleBar()->setCustomWidget(titlebar, Qt::AlignVCenter, false);
    this->setCentralWidget(widget);

    sound_slider->setFixedWidth(100);

    bottom_layout->addWidget(time);
    bottom_layout->addStretch();
    bottom_layout->addWidget(stop_button);
    bottom_layout->addWidget(left_button);
    bottom_layout->addWidget(play_button);
    bottom_layout->addWidget(right_button);
    bottom_layout->addWidget(sound_slider);
    bottom_layout->addStretch();
    bottom_layout->addWidget(full_button);

    slider_layout->addWidget(play_slider);

    main_layout->addWidget(renderer->widget());
    main_layout->addLayout(slider_layout);
    main_layout->addLayout(bottom_layout);

    main_layout->setMargin(0);
    main_layout->setSpacing(0);
    bottom_layout->setMargin(10);
    bottom_layout->setSpacing(10);

    time->hide();

    widget->setLayout(main_layout);
}

void MainWindow::play_button_clicked()
{
    if (open_file_name.isEmpty())
    {
        play_button_open_file();
    }
    else
    {
        play_button_state();
    }
}

void MainWindow::play_button_open_file()
{
    open_file_name = QFileDialog::getOpenFileName(0, tr("Open a video"));
    QFileInfo file_name = QFileInfo(open_file_name);

    m_player->play(open_file_name);
    play_button->setText("Pause");
    time->show();

    titlebar->setFileName(file_name.fileName());
}

void MainWindow::play_button_state()
{
    if (m_player->state() == m_player->PlayingState)
    {
        m_player->pause(true);
        play_button->setText("Play");
    }
    else if (m_player->state() == m_player->PausedState)
    {
        m_player->pause(false);
        play_button->setText("Pause");
    }

}

void MainWindow::stop_button_clicked()
{
    open_file_name = "";
    time->hide();

    m_player->stop();
    play_button->setText("Play");
    titlebar->setFileName("");
}

void MainWindow::seek_by_slider(int value)
{
    if (!m_player->isPlaying())
        return;

    m_player->seek(qint64(value * m_unit));
}

void MainWindow::seek_by_slider()
{
    seek_by_slider(play_slider->value());
}

void MainWindow::update_slider(qint64 value)
{
    play_slider->setRange(0, int(m_player->duration() / m_unit));
    play_slider->setValue(int(value / m_unit));
}

void MainWindow::update_slider()
{
    update_slider(m_player->position());
}

void MainWindow::update_slider_unit()
{
    m_unit = m_player->notifyInterval();
    update_slider();
}
