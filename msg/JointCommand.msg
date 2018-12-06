std_msgs/Header header

# Joint names
string[] name

# Desired values
float32[] position
float32[] velocity
float32[] effort
float32[] stiffness
float64[] damping
uint8[] ctrl_mode

# Auxiliary field
string aux_name
float32[] aux
