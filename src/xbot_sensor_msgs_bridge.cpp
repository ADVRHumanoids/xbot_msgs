#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <xbot_msgs/JointCommand.h>
#include <xbot_msgs/JointState.h>

ros::Publisher g_xbot_cmd_pub, g_ros_jstate_pub;

void on_ros_cmd_received(const sensor_msgs::JointStateConstPtr& msg);
void on_xbot_jstate_received(const xbot_msgs::JointStateConstPtr& msg);

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "xbot_sensor_msgs_bridge");
    ros::NodeHandle nh("xbotcore");
    
    ros::Subscriber ros_cmd_sub = nh.subscribe("ros_command", 
                                               1, 
                                               on_ros_cmd_received, 
                                               ros::TransportHints().tcpNoDelay());
    
    ros::Subscriber xbot_jstate_sub = nh.subscribe("joint_states", 
                                                   1, 
                                                   on_xbot_jstate_received, 
                                                   ros::TransportHints().tcpNoDelay());
    
    g_ros_jstate_pub = nh.advertise<sensor_msgs::JointState>("ros_joint_states", 1);
    
    g_xbot_cmd_pub = nh.advertise<xbot_msgs::JointCommand>("command", 1);
    
    ros::spin();
    
}

void on_ros_cmd_received(const sensor_msgs::JointStateConstPtr& msg)
{
    xbot_msgs::JointCommand xb_msg;
    xb_msg.header = msg->header;
    xb_msg.position.assign(msg->position.begin(), msg->position.end());
    xb_msg.velocity.assign(msg->velocity.begin(), msg->velocity.end());
    xb_msg.effort.assign(msg->effort.begin(), msg->effort.end());
    xb_msg.name.assign(msg->name.begin(), msg->name.end());
    
    /* Control mode handling */
    xb_msg.ctrl_mode.assign(xb_msg.name.size(), 1 + 2 + 4);
    
    g_xbot_cmd_pub.publish(xb_msg);
}

void on_xbot_jstate_received(const xbot_msgs::JointStateConstPtr& msg)
{
    sensor_msgs::JointState ros_msg;
    ros_msg.header = msg->header;
    ros_msg.position.assign(msg->motor_position.begin(), msg->motor_position.end());
    ros_msg.velocity.assign(msg->motor_velocity.begin(), msg->motor_velocity.end());
    ros_msg.effort.assign(msg->effort.begin(), msg->effort.end());
    ros_msg.name.assign(msg->name.begin(), msg->name.end());
    
    g_ros_jstate_pub.publish(ros_msg);
}


