#pragma once

#include <string>

#include <QMainWindow>
#include <QListWidgetItem>
#include <osutool/parsing/beatmapset.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(const std::string& beatmapSetDir, QWidget* parent = 0);
    ~MainWindow();
    void listBeatmapSets(std::string path);
    void listBeatmaps(const osutool::parsing::BeatmapSet& beatmapSet);

  private slots:
    void onItemClicked(QListWidgetItem* item);

  private:
    Ui::MainWindow* ui;
};
