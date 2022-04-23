TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += editor.c \
    load.c \
    move.c \
    funcs.c \
    save.c \
    show.c \
    append_line.c \
    create_text.c \
    move_cursor.c \
    process_forward.c \
    remove_all.c

HEADERS += text.h \
    _text.h \
    common.h

QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov