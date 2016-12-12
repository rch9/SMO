#include "mainwidget.h"
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <iostream>


MainWidget::MainWidget():
    QWidget(),
    table(new TabTableWidget()),
    smo(new TabSMOWidget()),
    tabs(new QTabWidget()),
    restart(new QPushButton(tr("restart"))),
    label(new QLabel()) {

    initMainWidget();

    connect(restart, SIGNAL(clicked()), this, SLOT(clickRestart()));

    QPalette Pal;
    Pal.setColor(QPalette::Background, Qt::white);
    setPalette(Pal);
}

// НУ ТУТ СТРЕМНО, ДА
MainWidget::~MainWidget() {
    delete table;
    delete smo;
    delete tabs;
    delete restart;
}

void MainWidget::initMainWidget() {
    label->setParent(smo);
    label->move(200, 200);

    tabs->setParent(this);
    tabs->setFixedSize(600, 400);

    restart->setParent(this);
    restart->move(300, 500);

    tabs->addTab(table, "first");
    tabs->addTab(smo, "second");

    setFixedSize(600, 600);
}

void MainWidget::clickRestart() {
    label->setText("HELLO WORLD");
}