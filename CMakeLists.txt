cmake_minimum_required(VERSION 3.8)
project(xbot_msgs VERSION 1.0.0)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)

# Generate messages in the 'msg' folder
set(msg_files
  msg/JointState.msg
  msg/CustomState.msg
  msg/JointCommand.msg
  msg/JointDeviceInfo.msg
  msg/PingPong.msg
  msg/Statistics2.msg
  msg/Statistics.msg
  msg/AuxState.msg
  msg/TaskStatistics.msg
  msg/ThreadStatistics.msg
  msg/LifecycleEvent.msg
  msg/Fault.msg
)

# Generate services in the 'srv' folder
set(srv_files
  srv/PluginCommand.srv
  srv/PluginStatus.srv
  srv/GetPluginList.srv
  srv/SetControlMask.srv
  srv/SetAuxFields.srv
  srv/StartProcess.srv
  srv/StopProcess.srv
  srv/GetStringList.srv
  srv/SetString.srv
)

rosidl_generate_interfaces(${PROJECT_NAME}
    ${msg_files}
    ${srv_files}
    DEPENDENCIES
    builtin_interfaces
    sensor_msgs
    std_msgs
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()

include(cmake/GenerateDeb.cmake)
