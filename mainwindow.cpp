#include "mainwindow.h"
#include <qsplitter.h>
#include <QGridLayout>
#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <analitzaplot/plotsmodel.h>
#include <analitzagui/plotsview3d.h>
#include <analitzaplot/plotsfactory.h>
#include <analitza/expression.h>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QObject>
#include <QWidget>
#include <QDockWidget>
#include <QListWidget>
#include <QColor>
#include <QStringList>
#include <QDebug>
#include <iostream>

using namespace Analitza;

MainWindow::MainWindow(KCmdLineArgs* args)
{
    this->setMinimumSize(640, 480);
    QSplitter *central = new QSplitter(Qt::Vertical, this);
    central->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    model = new PlotsModel(central);
    QLabel *label = new QLabel("Equation");
    textfield = new QLineEdit();
    QPushButton *plotb = new QPushButton();
    plotb->setText("Plot");
    PlotsView3D *view3d = new PlotsView3D();
    sfactory = PlotsFactory::self();
    view3d->setUseSimpleRotation(args->isSet("simple-rotation"));
     view3d->setModel(model);
     QWidget *widget=new QWidget(this);
     QGridLayout *layout = new QGridLayout;
     layout->addWidget(label,0,0);
     layout->addWidget(textfield,0,1);
    layout->addWidget(plotb,0,2);
     layout->addWidget(view3d,1,0,1,3);
     widget->setLayout(layout);
     setCentralWidget(widget);
     widget->connect(plotb,SIGNAL(clicked()),this,SLOT(buttonclicked()));
     createDockWindows();
     random=0;
     setColorList();
     this->show();
}

MainWindow::~MainWindow()
{

}
void MainWindow::setColorList(){
    list.append(Qt::green);
    list.append(Qt::yellow);
    list.append(Qt::cyan);
    list.append(Qt::red);
    list.append(Qt::darkCyan);
    list.append(Qt::magenta);
    list.append(Qt::darkGreen);
    list.append(Qt::blue);
    list.append(Qt::white);
}

void MainWindow::buttonclicked (){
     equation = textfield->text();
     model->addPlot(sfactory->requestPlot(Analitza::Expression(equation), Dim3D).create(list.at(random%9),"implicit 2"));
     PlotList->addItem(equation);
    random++;
}

void MainWindow::createDockWindows()
{
     dock = new QDockWidget(tr("Recent Plots"), this);
     dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
     PlotList = new QListWidget(dock);
     dock->setWidget(PlotList);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}
