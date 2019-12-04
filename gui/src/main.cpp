#include <iostream>

#include <QApplication>
#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "error: Expected the beatmapset directory as an argument." << std::endl;
        return 1;
    }

    QApplication a(argc, argv);
    MainWindow w(argv[1]);
    w.show();

    return a.exec();
}
