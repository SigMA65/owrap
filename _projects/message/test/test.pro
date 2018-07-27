TEMPLATE = app

DEBUG_TARGET = message_testd
RELEASE_TARGET = message_test

include( ../message.pri )

#message($$OUTINCLUDE)
LIBS += -L$$OUTDIR/lib
LIBS += -lmessage



#HEADERS += \
#    ../src/message.h

SOURCES += \
    ../src/message_test.cpp
