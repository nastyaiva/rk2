#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "./../Command.cpp"
// Include the header files for the classes you want to test
#include "Command.hpp"

// Test fixture for Receiver class
class ReceiverTest : public ::testing::Test {
protected:
  Receiver receiver;
};

TEST_F(ReceiverTest, ActionTest) {
  testing::internal::CaptureStdout();
  receiver.action();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Receiver: execute action\n");
}

// Test fixture for ConcreteCommand class
class ConcreteCommandTest : public ::testing::Test {
protected:
  Receiver* receiver = new Receiver();
  Command* command = new ConcreteCommand(receiver);
};

TEST_F(ConcreteCommandTest, ExecuteTest) {
  testing::internal::CaptureStdout();
  command->execute();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Receiver: execute action\n");
}

// Test fixture for Invoker class
class InvokerTest : public ::testing::Test {
protected:
  Receiver* receiver = new Receiver();
  Command* command = new ConcreteCommand(receiver);
  Invoker invoker;
};

TEST_F(InvokerTest, ConfirmTest) {
  invoker.set(command);
  testing::internal::CaptureStdout();
  invoker.confirm();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Receiver: execute action\n");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
