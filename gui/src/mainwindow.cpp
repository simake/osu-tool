#include <boost/filesystem/path.hpp>

#include <QMainWindow>
#include <QListWidgetItem>
#include <QPixmap>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <osutool/parsing/beatmap.hpp>
#include <osutool/parsing/beatmapset.hpp>

namespace op = osutool::parsing;
namespace fs = boost::filesystem;

Q_DECLARE_METATYPE(op::BeatmapSet);
Q_DECLARE_METATYPE(op::Beatmap);

MainWindow::MainWindow(const fs::path& beatmapSetDir, QWidget* parent)
        : QMainWindow(parent),
          ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(onBeatmapSetClicked(QListWidgetItem*)));

    connect(ui->listWidget_2, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(onBeatmapClicked(QListWidgetItem*)));

    listBeatmapSets(beatmapSetDir); // has to be defined externally for now
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::listBeatmapSets(const fs::path& path) {
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

void MainWindow::displayImage(const fs::path& path) {
    QPixmap pm(QString::fromStdString(path.string()));
    ui->label->setPixmap(pm.scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->label->setAlignment(Qt::AlignCenter);
}

void MainWindow::onBeatmapSetClicked(QListWidgetItem* item) {
    listBeatmaps(qvariant_cast<op::BeatmapSet>(item->data(Qt::UserRole)));
}

void MainWindow::onBeatmapClicked(QListWidgetItem* item) {
    op::Beatmap bm = qvariant_cast<op::Beatmap>(item->data(Qt::UserRole));
    fs::path bgPath = bm.getPath().parent_path() /= bm.getBackgrounds().at(0);
    displayImage(bgPath);
}
