#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsView>

#include <dlabel.h>
#include <dslider.h>
#include <dtextbutton.h>

#include <QtAV>
#include <QtAVWidgets>
#include <QtAV/AVPlayer.h>

DWIDGET_USE_NAMESPACE

using namespace QtAV;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);

    void initUI();

private:
    QString open_file_name;

private slots:
    void play_button_clicked();
    void play_button_open_file();
    void play_button_state();
    void stop_button_clicked();

private:
    QVBoxLayout *main_layout = new QVBoxLayout();
    QHBoxLayout *slider_layout = new QHBoxLayout();
    QHBoxLayout *bottom_layout = new QHBoxLayout();

    AVPlayer *m_player = new AVPlayer;
    VideoRendererId v = VideoRendererId_Widget;
    VideoRenderer* renderer = VideoRenderer::create(v);

    DSlider *play_slider = new DSlider(Qt::Horizontal);
    DLabel *time = new DLabel("00:00:00/00:00:00");
    DTextButton *stop_button = new DTextButton("Stop");
    DTextButton *left_button = new DTextButton("←");
    DTextButton *right_button = new DTextButton("→");
    DTextButton *play_button = new DTextButton("Play");
    DSlider *sound_slider = new DSlider(Qt::Horizontal);
    DTextButton *full_button = new DTextButton("Full");
};

#endif
