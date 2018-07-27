CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG -= debug_and_release debug_and_release_target

OUTDIR = ../../..
#���� ���������� ��� ���������, ������� ����� ��� ������� ��������
OUTINCLUDE = $$OUTDIR/include

OBJECTS_DIR = ../obj

CONFIG(debug, debug|release){
    TARGET = $$DEBUG_TARGET
}

CONFIG(release, debug|release){
    TARGET = $$RELEASE_TARGET
}

INCLUDEPATH += $(INCLUDE_C++) $(INCLUDE_BOOST) $(INCLUDE_MINGW) $$OUTINCLUDE

include(../main.pri)
