

#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"
#include "tutorial_interfaces/msg/num.hpp"     // CHANGE

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
    //publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    publisher_ = this->create_publisher<tutorial_interfaces::msg::Num>("topic", 10);    // CHANGE para emplear el msg definido en el paquete creado tutorial_interfaces
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    //auto message = std_msgs::msg::String();
    auto message = tutorial_interfaces::msg::Num();                               // CHANGE para emplear el msg definido en el paquete creado tutorial_interfaces
    //message.data = "Miguel sexy! " + std::to_string(count_++);
    message.num = this->count_++;                                        // CHANGE para emplear el msg definido en el paquete creado tutorial_interfaces
    //RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", message.num);    // CHANGE para emplear el msg definido en el paquete creado tutorial_interfaces
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  //rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr publisher_; // CHANGE para emplear el msg definido en el paquete creado tutorial_interfaces
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
