# CMakeList.txt: CMakeopencv 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("addlogo")
#set (3rdlib OpenCV)
set (OpenCV_DIR "C:/03study/opencv4.3/opencv/build")
find_package(OpenCV)
if(OpenCV_FOUND)
	include_directories(${OpenCV_INCLUDE_DIRS})
	link_libraries(${OpenCV_LIBS})
	
	message("OpenCV_INCLUDE_DIR : ${OpenCV_INCLUDE_DIRS}")
	#message("OpenCV_LIBRARY_DIRS : ${OpenCV_LIBRARY_DIRS}")
	#message("OpenCV_LIBS : ${OpenCV_LIBS}")
endif(OpenCV_FOUND)

# 将源代码添加到此项目的可执行文件。
add_executable (addlogo "addlogo.cpp" "addlogo.h")
#target_link_libraries(addlogo ${OpenCV_LIBS})
# TODO: 如有需要，请添加测试并安装目标。
