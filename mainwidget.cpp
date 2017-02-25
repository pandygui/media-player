#include "mainwidget.h"
#include <QFileDialog>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    open_file_name = "";

    m_player->setRenderer(renderer);

    connect(play_button, SIGNAL(clicked(bool)), this, SLOT(play_button_clicked()));
    connect(stop_button, SIGNAL(clicked(bool)), this, SLOT(stop_button_clicked()));

    initUI();
}

void MainWidget::initUI()
{
    sound_slider->setFixedWidth(100);

    bottom_layout->addWidget(time);
    bottom_layout->addWidget(stop_button);
    bottom_layout->addWidget(left_button);
    bottom_layout->addWidget(play_button);
    bottom_layout->addWidget(right_button);
    bottom_layout->addWidget(sound_slider);
    bottom_layout->addWidget(full_button);

    slider_layout->addWidget(play_slider);

    main_layout->addWidget(renderer->widget());
    main_layout->addLayout(slider_layout);
    main_layout->addLayout(bottom_layout);

    this->setLayout(main_layout);
}

void MainWidget::play_button_clicked()
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

void MainWidget::play_button_open_file()
{
    open_file_name = QFileDialog::getOpenFileName(0, tr("Open a video"));
    m_player->play(open_file_name);
    play_button->setText("Pause");
}

void MainWidget::play_button_state()
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

void MainWidget::stop_button_clicked()
{
    open_file_name = "";

    m_player->stop();
    play_button->setText("Play");
}
