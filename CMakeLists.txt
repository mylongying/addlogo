﻿cmake_minimum_required (VERSION 3.8)
set(3rd "OpenCV")
set(project "addlogo")
set(source "cximage.cpp")
set(preheader 1)
if (preheader)
	include(pheader.cmake)
	set(source ${source} "pch.cpp")
endif(preheader)
project (${project})
#set(${3rd}_DIR "C:/03study/opencv4.3/opencv/build")
#set(${3rd}_DIR "C:/opencv440/opencv/build")
set(${3rd}_DIR "C:/opencv/build")

find_package(${3rd} REQUIRED)
if(${3rd}_FOUND)
	include_directories( ${${3rd}_INCLUDE_DIRS} "E:/06study/cximage/CxImage")
	link_libraries(${${3rd}_LIBS})
	add_executable (${project}  ${source} )
	#TARGET_LINK_LIBRARIES(${project} ${OpenCV_LIBS})
	if (preheader)
		add_precompiled_header(${project} pch.h SOURCE_CXX pch.cpp FORCEINCLUDE)
	endif(preheader)
else(${3rd}_FOUND)
	message(FATAL_ERROR "can not find ${3rd}")
endif(${3rd}_FOUND)