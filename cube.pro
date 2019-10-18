QT       += core gui widgets

TARGET = openglcube
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp

SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp

HEADERS += \
    mainwidget.h \
    geometryengine.h \
    mainwindow.h

RESOURCES += \
    shaders.qrc \
    textures.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/cube
INSTALLS += target

FORMS += \
    mainwindow.ui
