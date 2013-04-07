<<<<<<< HEAD
/**
 * Created by Punit Mehta
 * E-Mail : punit9462@gmail.com
 */
=======
>>>>>>> 2907468fb16963912db5a064a89a6646af3b6154
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
<<<<<<< HEAD
#include <QtCore/QString>
#include <QLineEdit>
#include <QtCore/QObject>
#include <QMainWindow>
#include <QListWidget>
#include <QtCore/QList>
#include <qtreeview.h>
#include <QtCore/QString>
#include <QMenu>

using namespace Analitza;
/** A MainWindow Class
 * MainWindow class creates main window which is used to type the equation as well as to plot it
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * A constructor which is used to construct the mainwinow object
     */
    MainWindow(KCmdLineArgs* args);
    /**
     * A destructor that destorys the mainwinow object created by the constructor
     */
    ~MainWindow();
protected:
    /**
     * This method allows to create pop-up menu on right click
     * Using this mehtod , user can select the options available on right click. These options include
     * changing the equation , showing and hiding the plots that user wants and also deleting the exiting
     * Plot equation.
     */
    void contextMenuEvent(QContextMenuEvent *event);
    /**
     * This method creates actions and their implementation available on right click
     * Using this mehtod , user can use select the options available on right click. These options include
     * changing the equation , showing and hiding the plots that user wants and also deleting the exiting
     * Plot equation.
     */
    void createActions();
    /**
     * This method reimplements the plot when user changes the equation.
     * When user hits the change equation button , this method removes the old equation's plot
     * and reimplement the newer one which is entered by the user.
     */
    void ReimplementPlots();
    /**
     * It is used to set the available list of colors in the QList<Qt::GlobalColor> object named m_list.
     */
    void setColorList();
    /**
     * It is used to keep track of every item stored in PlotModel object named m_model and QListWidget object m_listwidget.
     * This method helps the user to store the Ploting equations on the same indexes in the both QListWidget's object
     * and PlotModel's Object.
     */
    void correction();
signals:
public slots:
    /**
     * This slot gets activated when the user hits the Plot button in the MainWindow
     * This method plots the equation on the PlotView3D object and also makes the equation along with
     * the respective graph's color visible on the TreeView.
     */
    void buttonclicked();
    /**
     * This slot is used when the user clicks on the equation to change/hide/delete the mathematical formula.
     * The slot is connected when any item on QListWidget's object named listwidget is clicked/doubleclicked.
     * It makes the content of that perticular item editable on the widget
     * and  stores the index of the item that is clicked in the vairable m_rowchanged.
     */
    void afteritemchanged(QListWidgetItem *item); // for listwidget
    /**
     * This slot is used when the user clicks on the equation to hide the mathematical formula and its graph.
     * The slot is connected when any item on QListWidget's object named listwidget2 is clicked/doubleclicked.
     * It makes the content of that perticular item eqitable on the widget
     * and stores the index of the item that is clicked in the vairable m_rowchanged2.
     */
    void afteritemchanged2(QListWidgetItem *item); // for listwidget2
    /**
     * This slot is used whenever change equation button is clicked by the user.
     * The purpose of this slot is to create a widget which shows the available list of plots
     * sothat the user can select the equation , he wants to change.
     */
    void changeActionclicked();
    /**
     * This slot is used whenever delete equation button is clicked by the user.
     * The purpose of this slot is to create a widget which shows the available list of plots
     * sothat the user can select the equation , he wants to delete.
     */
    void deleteActionclicked();
    /**
     * This slot is used whenever hide equation button is clicked by the user.
     * The purpose of this slot is to create a widget which shows the available list of plots which are hidden
     * and can be restored and also the exiting plots from which the user can chose the plot to hide it.
     */
    void hideActionclicked();
    /**
     * This slot is used when the user hits the submit button available in the widget
     * generated by selecting the change equation choice.
     */
    void changesubmitClicked();
    /**
     * This slot is used when the user hits the submit button available in the widget
     * generated by selecting the delete equation choice
     */
    void deletesubmitClicked();
    /**
     * This slot is used when the user hits the hide button available in the widget
     * generated by selecting the hide equation choice
     */
    void hideClicked();
    /**
     * This slot is used when the user hits the show button available in the widget
     * generated by selecting the hide equation choice
     */
    void showClicked();
    /**
     * This slot is used when the user hits the close button available in the widget
     * generated by selecting the change equation choice
     */
    void changecloseClicked();
    /**
     * This slot is used when the user hits the close button available in the widget
     * generated by selecting the delete equation choice
     */
    void deletecloseClicked();
    /**
     * This slot is used when the user hits the close button available in the widget
     * generated by selecting the hide equation choice
     */
    void hidecloseClicked();
private:
    PlotsFactory *m_sfactory;
    PlotsModel *m_model;
    PlotsView3D *m_view3d;
    QList<Qt::GlobalColor> m_list; /* list used to save colors */
    QString m_equation ; /* string having an equation */
    QLineEdit *m_textfield;
    QAction *m_ChangeEquation;
    QAction *m_DeleteEquation;
    QAction *m_HideEquation;
    QTreeView *m_treeview;
    QListWidget *m_listwidget;
    QWidget *m_changeActionDialogue;
    QWidget *m_deleteActionDialogue;
    QWidget *m_hideActionDialogue;
    QListWidget *m_listwidget2;
    QMenu *m_menu; /* menu generated on right click */
    int m_size2; /* size of listwidget2 */
    int m_rowchanged2; /* index of the row clicked in listwidget2 */
    int m_rowchanged;  /* index of the row clicked in listwidget */
    int m_size; /* size of listwidget */
    int m_random; /*random variable to get colors from the list. */
};
#endif // MAINWINDOW_H
=======
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

>>>>>>> 2907468fb16963912db5a064a89a6646af3b6154
