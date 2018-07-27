TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

#Добавленное

CONFIG -= debug_and_release debug_and_release_target

DEBUG_TARGET = wrapreld
RELEASE_TARGET = wraprel

OUTDIR = ../..
#Сюда собираются все заголовки, которые нужны для внешних проектов
OUTINCLUDE = $$OUTDIR/include

#message($$OUTINCLUDE)

#OUTDIR = OUT_PWD
DESTDIR = bin

# объектные файлы
OBJECTS_DIR = obj

CONFIG(debug, debug|release){
    TARGET = $$DEBUG_TARGET
}

CONFIG(release, debug|release){
    TARGET = $$RELEASE_TARGET
}

#INCLUDEPATH += $(INCLUDE_C++) $(INCLUDE_BOOST) $(INCLUDE_MINGW)
INCLUDEPATH += $(INCLUDE_C++) $(INCLUDE_BOOST) $(INCLUDE_MINGW) $$OUTINCLUDE
LIBS += -L$(LIB_BOOST) -llibboost_regex-mgw46-mt-1_54
LIBS += -L$$OUTDIR/lib
LIBS += -lmessage -lregex


#QMAKE_CXXFLAGS += -std=gnu++11
QMAKE_CXXFLAGS += -std=gnu++0x


OTHER_FILES += readme.txt src\\config.cnf

# Не поддерживается в win
DISTFILES += readme.txt


HEADERS += \
    src/wrap.h \
    src/property.h \
    src/constants.h

SOURCES += \
    src/wrap.cpp \
    src/property.cpp





