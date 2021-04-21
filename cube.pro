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


contains(QMAKE_CC, arm-openstlinux_eglfs-linux-gnueabi-gcc) {
    DEFINES += PLATFORM_ARM

    CONFIG(debug, debug|release) {
        message("Configuring for ARM-Debug build ...")
        DEFINES += PLATFORM_DEBUG
    } else {
        message("Configuring for ARM-Release build ...")
        DEFINES += PLATFORM_RELEASE
    }
} else {
    DEFINES += PLATFORM_X86

    CONFIG(debug, debug|release) {
        message("Configuring for X86-Debug build ...")
        DEFINES += PLATFORM_DEBUG
    } else {
        message("Configuring for X86-Release build ...")
        DEFINES += PLATFORM_RELEASE
    }
}


# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/cube
INSTALLS += target

FORMS += \
    mainwindow.ui
