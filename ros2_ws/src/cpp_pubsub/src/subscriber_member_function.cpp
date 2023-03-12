

#include <memory>

#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"
#include "tutorial_interfaces/msg/num.hpp"     // CHANGE para usar tutorial_interfaces
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    //subscription_ = this->create_subscription<std_msgs::msg::String>(
    subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>(          // CHANGE para usar tutorial_interfaces
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

private:
  //void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
  void topic_callback(const tutorial_interfaces::msg::Num::SharedPtr msg) const       // CHANGE para usar tutorial_interfaces
  {
    //RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
    RCLCPP_INFO(this->get_logger(), "I heard: '%d'", msg->num);              // CHANGE para usar tutorial_interfaces
  }
  //rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
  rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_; // CHANGE para usar tutorial_interfaces
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
