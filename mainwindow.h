#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <qsplitter.h>
#include <QGridLayout>
#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <analitzaplot/plotsmodel.h>
#include <analitzaplot/spacecurve.h>
#include <analitzagui/plotsview3d.h>
#include <analitzaplot/plotsfactory.h>
#include <analitza/expression.h>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QObject>

using namespace Analitza;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
     MainWindow(KCmdLineArgs* args);
    ~MainWindow();
protected:

signals:

public slots:
     void buttonclicked ();
private:
    PlotsFactory* sfactory;
    QString equation ;
    PlotsModel *model;
    QLineEdit *textfield;
};

#endif // MAINWINDOW_H

