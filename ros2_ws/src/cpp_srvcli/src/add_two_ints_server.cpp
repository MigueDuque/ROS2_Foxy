#include "rclcpp/rclcpp.hpp"
//#include "example_interfaces/srv/add_two_ints.hpp"
#include "tutorial_interfaces/srv/add_three_ints.hpp"     // CHANGE

#include <memory>

//void add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
void add(const std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Request> request,     // CHANGE
          //std::shared_ptr<example_interfaces::srv::AddTwoInts::Response>      response)
          std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Response>       response)  // CHANGE
{
  //response->sum = request->a + request->b;
  response->sum = request->a + request->b + request->c;                                       // CHANGE
  //RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
  //              request->a, request->b);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld" " c: %ld",   // CHANGE
                request->a, request->b, request->c);                                          // CHANGE
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  //std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_server");
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_three_ints_server");  // CHANGE


  //rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service =
    //node->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", &add);
  rclcpp::Service<tutorial_interfaces::srv::AddThreeInts>::SharedPtr service =                 // CHANGE
    node->create_service<tutorial_interfaces::srv::AddThreeInts>("add_three_ints",  &add);     // CHANGE

  //RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to suck Miguel's dick uwu.");      // CHANGE

  rclcpp::spin(node);
  rclcpp::shutdown();
}