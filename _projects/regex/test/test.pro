TEMPLATE = app

DEBUG_TARGET = regex_testd
RELEASE_TARGET = regex_test

include( ../regex.pri )

LIBS += -L$$OUTDIR/lib
LIBS += -lmessage

CONFIG(release, debug|release){
  LIBS += -lregex
}

CONFIG(debug, debug|release){
  LIBS += -lregexd
}


LIBS += -L$(LIB_BOOST) -llibboost_regex-mgw46-mt-1_54


SOURCES += \
    ../src/regex_test.cpp
