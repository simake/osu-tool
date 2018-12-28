#pragma once

#include <QMainWindow>
#include <osutool/parsing/beatmapset.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();
    void listBeatmapSets(std::string path);
    void listBeatmaps(const osutool::parsing::BeatmapSet& beatmapSet);

  private:
    Ui::MainWindow* ui;
};
