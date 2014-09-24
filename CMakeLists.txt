##############################################################################
# Cmake
##############################################################################

cmake_minimum_required(VERSION 2.8.3)
project(dslam_viewer)

##############################################################################
# Find Packages
##############################################################################

find_package(catkin REQUIRED COMPONENTS
    ecl_linear_algebra
    sophus
)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
set(QT_INCLUDE_DIRS_NO_SYSTEM TRUE)
find_package(Qt4 COMPONENTS QtCore QtGui QtOpenGL)
include(${QT_USE_FILE})
find_path(QGLViewer_INCLUDE_DIRS QGLViewer/qglviewer.h)
find_library(QGLViewer_LIBRARY NAMES QGLViewer)

##############################################################################
# Catkin
##############################################################################

catkin_package(
#    INCLUDE_DIRS include 
#    LIBRARIES ${PROJECT_NAME} 
#    CATKIN_DEPENDS
    DEPENDS GLUT OpenGL QT
    )

##############################################################################
# Project Configuration
##############################################################################

dslam_desktop_setup()
add_definitions(${catkin_DEFINITIONS})
include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${QGLViewer_INCLUDE_DIRS}
    ${QT_INCLUDES}    # list of escaped QtCore, ... subdirs.
    ${QT_INCLUDE_DIR} # the root level qt4 dir
    ${GLUT_INCLUDE_DIRS}
    ${OpenGL_INCLUDE_DIRS}
)

##############################################################################
# Sources
##############################################################################

add_subdirectory(include)
add_subdirectory(src)

##############################################################################
# Installs
##############################################################################

#install(DIRECTORY resources DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
#install(DIRECTORY ui DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})