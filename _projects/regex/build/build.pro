TEMPLATE = lib

DEBUG_TARGET = regexd
#DEBUG_TARGET = regex
RELEASE_TARGET = regex

include( ../regex.pri )

DLLDESTDIR = $$OUTDIR/bin
DESTDIR = $$OUTDIR/lib

LIBS += -L$(LIB_BOOST) -llibboost_regex-mgw46-mt-1_54

SOURCES += \
    ../src/regexMy.cpp \
    ../src/regex.cpp

HEADERS += \
    ../src/regexMy.h \
    ../src/regex.h

copyHeaders2OutInclude()


