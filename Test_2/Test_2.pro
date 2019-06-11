QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_sample.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-Gaiiulin_LAB_4-Desktop/release/ -lGaiiulin_LAB_4
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-Gaiiulin_LAB_4-Desktop/debug/ -lGaiiulin_LAB_4
else:unix: LIBS += -L$$PWD/../build-Gaiiulin_LAB_4-Desktop/ -lGaiiulin_LAB_4

INCLUDEPATH += $$PWD/../Gaiiulin_LAB_4
DEPENDPATH += $$PWD/../Gaiiulin_LAB_4

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-Gaiiulin_LAB_4-Desktop/release/libGaiiulin_LAB_4.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-Gaiiulin_LAB_4-Desktop/debug/libGaiiulin_LAB_4.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-Gaiiulin_LAB_4-Desktop/release/Gaiiulin_LAB_4.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-Gaiiulin_LAB_4-Desktop/debug/Gaiiulin_LAB_4.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-Gaiiulin_LAB_4-Desktop/libGaiiulin_LAB_4.a
