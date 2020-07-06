QT += core
QT -= gui
QT+=network
QT+=sql
CONFIG += c++11

TARGET = Server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    server.cpp \
    sqlconnect.cpp

HEADERS += \
    server.h \
    sqlconnect.h
