QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bishop.cpp \
    gameboard.cpp \
    interface.cpp \
    king.cpp \
    knight.cpp \
    main.cpp \
    nullpiece.cpp \
    pawn.cpp \
    piece.cpp \
    queen.cpp \
    rook.cpp \
    schach_board.cpp \
    client.cpp \
    server.cpp

HEADERS += \
    bishop.hpp \
    gameboard.hpp \
    interface.h \
    king.hpp \
    knight.hpp \
    nullpiece.h \
    pawn.hpp \
    piece.hpp \
    queen.hpp \
    rook.hpp \
    schach_board.h \
    client.h \
    server.h

FORMS += \
    interface.ui \
    schach_board.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pieces.qrc
