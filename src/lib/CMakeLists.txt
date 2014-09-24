##############################################################################
# Qt
##############################################################################

QT4_WRAP_CPP(MOC_SOURCES
    ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/dslam_viewer.hpp
    ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/impl/gui_receiver.hpp
    simple_dialog.hpp
)
QT4_WRAP_UI(UI_INTERFACE_SOURCES
    ${PROJECT_SOURCE_DIR}/ui/main_window.ui
    ${PROJECT_SOURCE_DIR}/ui/simple_dialog.ui
)
include_directories(${CMAKE_CURRENT_BINARY_DIR})  # this is where ui headers are dropped.

##############################################################################
# Sources
##############################################################################

file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp) 
file(GLOB GL_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} gl/*.cpp) 

##############################################################################
# Library
##############################################################################

add_library(${PROJECT_NAME} ${SOURCES} ${GL_SOURCES} ${MOC_SOURCES} ${UI_INTERFACE_SOURCES})
target_link_libraries(${PROJECT_NAME}
    ${catkin_LIBRARIES}
    ${QGLViewer_LIBRARY}
    ${QT_LIBRARIES}
    ${GLUT_LIBRARY}
    ${OPENGL_LIBRARY}
) 

##############################################################################
# Installs
##############################################################################
 
install(TARGETS ${PROJECT_NAME}
   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

