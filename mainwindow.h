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
#include <QMainWindow>
#include <QDockWidget>
#include <QListWidget>
#include <QList>

using namespace Analitza;
class MainWindow : public QMainWindow
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
    QList<Qt::GlobalColor> list; //for colors
    void createDockWindows();
    void setColorList(); // saving colors in the list
    PlotsFactory* sfactory;
    QString equation ;
    PlotsModel *model;
    QLineEdit *textfield;
    QDockWidget *dock;
    QListWidget *PlotList;
    int random; //random variable to get colors from the list.
};

#endif // MAINWINDOW_H

