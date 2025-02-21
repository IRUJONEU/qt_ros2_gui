cmake_minimum_required(VERSION 3.8)
project(qt_ros2_gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

set(qt_ros2_gui_UIS
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/mainwindow.ui
)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

include_directories(
  include
  ui
)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(qt_ros2_gui
    src/main.cpp
    src/mainwindow.cpp
    include/mainwindow.h
    ${qt_ros2_gui_UIS}
)

target_link_libraries(qt_ros2_gui
    Qt5::Widgets
    ${rclcpp_LIBRARIES}
    ${std_msgs_LIBRARIES}
)
ament_target_dependencies(qt_ros2_gui rclcpp std_msgs)

install(TARGETS
  qt_ros2_gui
  DESTINATION lib/${PROJECT_NAME})

ament_package()
