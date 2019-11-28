
QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    gestion_patient.cpp \
    ajouter_patient.cpp \
    modifier_patient.cpp \
    supprimer_patient.cpp \
    recherche_patient.cpp \
    connection.cpp \
    patient.cpp \
    afficher_patient.cpp \
    recherche_patient_2.cpp \
    modifier.cpp

HEADERS += \
        mainwindow.h \
    gestion_patient.h \
    ajouter_patient.h \
    modifier_patient.h \
    supprimer_patient.h \
    recherche_patient.h \
    connection.h \
    patient.h \
    afficher_patient.h \
    recherche_patient_2.h \
    modifier.h

FORMS += \
        mainwindow.ui \
    gestion_patient.ui \
    ajouter_patient.ui \
    modifier_patient.ui \
    supprimer_patient.ui \
    recherche_patient.ui \
    afficher_patient.ui \
    recherche_patient_2.ui \
    modifier.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc
