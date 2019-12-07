#pragma once

#include <boost/filesystem/path.hpp>

#include <QMainWindow>
#include <QListWidgetItem>

#include <osutool/parsing/beatmapset.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(const boost::filesystem::path& beatmapSetDir, QWidget* parent = 0);
    ~MainWindow();
    void listBeatmapSets(const boost::filesystem::path& path);
    void listBeatmaps(const osutool::parsing::BeatmapSet& beatmapSet);
    void displayImage(const boost::filesystem::path& path);

  private slots:
    void onBeatmapSetClicked(QListWidgetItem* item);
    void onBeatmapClicked(QListWidgetItem* item);

  private:
    Ui::MainWindow* ui;
};
