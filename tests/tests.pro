include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIR=\\\"$$PWD/input/\\\"

HEADERS += func_tests.h \
	../app/common.h \
	../app/test.h

SOURCES +=     main.cpp \
	../app/create_text.c \
	../app/process_forward.c \
	../app/move_cursor.c \
	../app/move_cursor_right.c \
	../app/remove_all.c \
	../app/remove_first.c \
	../app/move.c \
	../app/show.c \
	../app/append_line.c \
	../app/funcs.c
	

INCLUDEPATH += ../app

DISTFILES += \
    input/TestSTDOut_output.txt
