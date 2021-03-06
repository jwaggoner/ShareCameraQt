

cmake_minimum_required(VERSION 2.8)
 
PROJECT(ShareCameraQt)
 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}) 

file(GLOB UI_FILES *.ui)
file(GLOB QT_WRAP *.h)
file(GLOB CXX_FILES *.cxx)

QT4_WRAP_UI(UISrcs ${UI_FILES})
QT4_WRAP_CPP(MOCSrcs ${QT_WRAP})
add_executable(ShareCameraQt MACOSX_BUNDLE ${CXX_FILES} ${UISrcs} ${MOCSrcs})
 
if(VTK_LIBRARIES)
  if(${VTK_VERSION} VERSION_LESS "6")
    target_link_libraries(ShareCameraQt ${VTK_LIBRARIES} QVTK)
  else()
    target_link_libraries(ShareCameraQt ${VTK_LIBRARIES})
  endif()
else()
  target_link_libraries(ShareCameraQt vtkHybrid QVTK vtkViews ${QT_LIBRARIES})
endif()

Enable_Testing()
add_executable(filePathTest Testing/filePathTest.cxx)
target_link_libraries(filePathTest ${QT_LIBRARIES} ${VTK_LIBRARIES} QVTK vtkViews vtkHybrid)
add_test(filePathTest  ${CMAKE_CURRENT_BINARY_DIR}/filePathTest)


add_executable(mapperTest Testing/mapper.cxx)
target_link_libraries(mapperTest ${QT_LIBRARIES} ${VTK_LIBRARIES} QVTK vtkViews vtkHybrid)
add_test(mapperTest  ${CMAKE_CURRENT_BINARY_DIR}/mapperTest)
