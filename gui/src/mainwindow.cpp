#include <QMainWindow>
#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <osutool/parsing/beatmap.hpp>
#include <osutool/parsing/beatmapset.hpp>

namespace op = osutool::parsing;

MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent),
          ui(new Ui::MainWindow) {
    ui->setupUi(this);
    listBeatmapSets("../../../parsing/test/beatmapsets");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::listBeatmapSets(std::string path) {
    std::vector<op::BeatmapSet> beatmapSets = op::getBeatmapSets(path);
    for (const auto& set : beatmapSets) {
        QString itemText = QString::fromStdString(set.getArtist() + " - " + set.getTitle());
        QListWidgetItem* item = new QListWidgetItem();
        item->setText(itemText);
        //item->setData(QListWidgetItem::UserType, )
        ui->listWidget->addItem(item);
    }
}

void MainWindow::listBeatmaps(const op::BeatmapSet& beatmapSet) {
    for (const auto& map : beatmapSet.getBeatmaps()) {
        QListWidgetItem* item = new QListWidgetItem();
        item->setText(QString::fromStdString(map.getDifficulty()));
        ui->listWidget_2->addItem(item);
    }
}
