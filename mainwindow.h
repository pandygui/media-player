#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsView>

#include <dlabel.h>
#include <dslider.h>
#include <dtextbutton.h>
#include "titlebar.h"
#include <DTitlebar>

#include <QtAV>
#include <QtAVWidgets>
#include <QtAV/AVPlayer.h>

DWIDGET_USE_NAMESPACE

using namespace QtAV;

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    void initUI();

private:
    QString open_file_name;
    int m_unit;

private slots:
    void play_button_clicked();
    void play_button_open_file();
    void play_button_state();
    void stop_button_clicked();

    void seek_by_slider(int value);
    void seek_by_slider();

    void update_slider(qint64 value);
    void update_slider();
    void update_slider_unit();

private:
    QWidget *widget = new QWidget();
    TitleBar *titlebar = new TitleBar();
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
