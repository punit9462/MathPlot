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
     QGridLayout *layout = new QGridLayout;
     layout->addWidget(label,0,0);
     layout->addWidget(textfield,0,1);
     layout->addWidget(plotb,0,2);
     layout->addWidget(view3d,1,0,1,3);
     this->setLayout(layout);
     connect(plotb,SIGNAL(clicked()),this,SLOT(buttonclicked()));
     this->show();
}

MainWindow::~MainWindow()
{

}
void MainWindow::buttonclicked (){
     equation = textfield->text();
     model->addPlot(sfactory->requestPlot(Analitza::Expression(equation), Dim3D).create(Qt::magenta, "implicit 2"));
   // qDebug() << "Done";
}
