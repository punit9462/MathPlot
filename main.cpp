/**
 * Created by Punit Mehta
 * E-Mail : punit9462@gmail.com
 */
#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <mainwindow.h>
#include <QMainWindow>
#include <qtreeview.h>
#include <qsplitter.h>
#include <QGridLayout>
#include <QStatusBar>
#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <QDebug>
#include "analitzaplot/surface.h"
#include "analitzaplot/spacecurve.h"
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
#include <mainwindow.h>
>>>>>>> 2907468fb16963912db5a064a89a6646af3b6154
using namespace Analitza;

int main(int argc, char *argv[])
{
    KAboutData aboutData("PlotView3DTest",
                         0,
                         ki18n("PlotView3DTest"),
                         "1.0",
                         ki18n("PlotView3DTest"),
                         KAboutData::License_LGPL_V3,
                         ki18n("Plot Demo"),
                         ki18n("PlotView3DTest"),
                         ki18n("PlotView3D"),
                         "1.0",
                         ki18n("PlotView3D"),
                         KAboutData::License_LGPL_V3,
                         ki18n("PlotView3D"),
                         "http://www.kde.org");

    KCmdLineArgs::init(argc, argv, &aboutData);
    KCmdLineOptions options;
    options.add("all-disabled", ki18n("marks all the plots as not visible"));
    options.add("simple-rotation", ki18n("uses simple rotation"));
    KCmdLineArgs::addCmdLineOptions(options);
    KCmdLineArgs* args = KCmdLineArgs::parsedArgs();
    QApplication app ( argc , argv );
    MainWindow  *window = new MainWindow(args);
    return app.exec();
}
