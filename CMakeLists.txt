cmake_minimum_required(VERSION 3.5)

project(ADVideoFusion VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets
    Multimedia
    MultimediaWidgets
    3DCore
    REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets
    Multimedia
    MultimediaWidgets
    3DCore
    REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        forms/AICCMdiSubWindow.hpp

        resources.qrc
)

#add_executable(ADVideoFusion
#    ${PROJECT_SOURCES}
#    )
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ADVideoFusion
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ADVideoFusion APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ADVideoFusion SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ADVideoFusion
            ${PROJECT_SOURCES}
        )
    endif()
endif()

#target_compile_options(ADVideoFusion PRIVATE -Wall -fvisibility=hidden -fno-rtti)

target_link_libraries(ADVideoFusion
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
    Qt${QT_VERSION_MAJOR}::3DCore
    )

set_target_properties(ADVideoFusion PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ADVideoFusion)
endif()
