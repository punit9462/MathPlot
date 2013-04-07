project(plot)
<<<<<<< HEAD
=======

>>>>>>> 2907468fb16963912db5a064a89a6646af3b6154
find_package( KDE4 REQUIRED )
find_package( Qt4 REQUIRED)
find_package ( OpenGL REQUIRED )
find_package ( Analitza REQUIRED )
<<<<<<< HEAD
include_directories( ${KDE4_INCLUDES} ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}  ${ANALITZA_INCLUDE_DIR}  ${OPENGL_INCLUDE_DIR}  )
set( plot_SRCS main.cpp mainwindow.cpp )
kde4_add_executable( plot ${plot_SRCS} )
=======

include_directories( ${KDE4_INCLUDES} ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}  ${ANALITZA_INCLUDE_DIR}  ${OPENGL_INCLUDE_DIR}  )
#-------------
set( plot_SRCS main.cpp mainwindow.cpp ) # may vary
kde4_add_executable( plot ${plot_SRCS} ) # correct
>>>>>>> 2907468fb16963912db5a064a89a6646af3b6154
target_link_libraries( plot ${KDE4_KDEUI_LIBS}  ${KDE4_KFILE_LIBS}
  ${ANALITZA_LIBRARY}
  ${ANALITZAGUI_LIBRARY}
  ${ANALITZAPLOT_LIBRARY}
<<<<<<< HEAD
=======
  # OpenGL
 # ${OPENGL_gl_LIBRARY}
 # ${OPENGL_glu_LIBRARY}
>>>>>>> 2907468fb16963912db5a064a89a6646af3b6154
  ${QT_QTOPENGL_LIBRARY}
  ${QT_QTXML_LIBRARY}
  ${QTMML_LIBRARY}
)
if(HAVE_OPENGL)
    target_link_libraries ( plot
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
    )
endif(HAVE_OPENGL)
install( TARGETS plot EXPORT DESTINATION ${INSTALL_TARGETS_DEFAULT_ARGS} )
<<<<<<< HEAD
=======

#install(TARGETS analitzagui  AnalitzaTargets ${INSTALL_TARGETS_DEFAULT_ARGS})

#Possible Problems : export path , opengl path not found , reinstall analitza
>>>>>>> 2907468fb16963912db5a064a89a6646af3b6154
