std_msgs/Header header

# Joint names
string[] name

# Sensed data
float32[] link_position
float32[] motor_position
float32[] link_velocity
float32[] motor_velocity
float32[] effort
uint16[] temperature_motor
uint16[] temperature_driver

# Desired values
float32[] position_reference
float32[] velocity_reference
float32[] effort_reference
float32[] stiffness
float32[] damping

# Fault
uint16[] fault

# Auxiliary field (usually for motor current)
string aux_name
float32[] aux