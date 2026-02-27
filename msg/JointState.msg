std_msgs/Header header

# Joint names
string[] name

# Sensed data
float32[] link_position
float32[] motor_position
float32[] link_velocity
float32[] motor_velocity
float32[] effort
float32[] motor_effort
float32[] temperature_motor
float32[] temperature_driver

# Desired values
float32[] position_reference
float32[] velocity_reference
float32[] effort_reference
float32[] stiffness
float32[] damping

# Status
uint8[] motor_status
uint8[] brake_status
