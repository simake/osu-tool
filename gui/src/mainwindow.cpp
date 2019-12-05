#include <string>

#include <QMainWindow>
#include <QListWidgetItem>
#include <QSharedPointer>
#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <osutool/parsing/beatmap.hpp>
#include <osutool/parsing/beatmapset.hpp>

namespace op = osutool::parsing;

Q_DECLARE_METATYPE(op::BeatmapSet);
Q_DECLARE_METATYPE(op::Beatmap);

MainWindow::MainWindow(const std::string& beatmapSetDir, QWidget* parent)
        : QMainWindow(parent),
          ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(onItemClicked(QListWidgetItem*)));

    listBeatmapSets(beatmapSetDir); // has to be defined externally for now
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::listBeatmapSets(std::string path) {
    ui->listWidget->clear();
    std::vector<op::BeatmapSet> beatmapSets = op::getBeatmapSets(path);
    for (const auto& set : beatmapSets) {
        QString itemText = QString::fromStdString(set.getArtist() + " - " + set.getTitle());
        QListWidgetItem* item = new QListWidgetItem();
        item->setText(itemText);
        item->setData(Qt::UserRole, QVariant::fromValue(set));
        ui->listWidget->addItem(item);
    }
}

void MainWindow::listBeatmaps(const op::BeatmapSet& beatmapSet) {
    ui->listWidget_2->clear();
    for (const auto& map : beatmapSet.getBeatmaps()) {
        QListWidgetItem* item = new QListWidgetItem();
        item->setText(QString::fromStdString(map.getDifficulty()));
        item->setData(Qt::UserRole, QVariant::fromValue(map));
        ui->listWidget_2->addItem(item);
    }
}


void MainWindow::onItemClicked(QListWidgetItem* item) {
    listBeatmaps(qvariant_cast<op::BeatmapSet>(item->data(Qt::UserRole)));
}
