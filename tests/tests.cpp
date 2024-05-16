#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "./../Command.cpp"

// Test case to check if the receiver performs the action correctly
TEST(CommandPatternTest, ReceiverAction) {
  Receiver receiver;
  
  testing::internal::CaptureStdout();
  receiver.action();
  std::string output = testing::internal::GetCapturedStdout();

  ASSERT_EQ(output, "Receiver: execute action\n");
}

// Test case to check if the concrete command executes correctly
TEST(CommandPatternTest, CommandExecute) {
  Receiver *receiver = new Receiver();
  ConcreteCommand command(receiver);
  
  testing::internal::CaptureStdout();
  command.execute();
  std::string output = testing::internal::GetCapturedStdout();

  ASSERT_EQ(output, "Receiver: execute action\n");
  delete receiver;
}

// Test case to check if the invoker confirms the command action
TEST(CommandPatternTest, InvokerConfirm) {
  Receiver *receiver = new Receiver();
  ConcreteCommand command(receiver);
  Invoker invoker;
  invoker.set(&command);
  
  testing::internal::CaptureStdout();
  invoker.confirm();
  std::string output = testing::internal::GetCapturedStdout();


  ASSERT_EQ(output, "Receiver: execute action\n");
  delete receiver;
}


  ASSERT_EQ(output, "Receiver: execute action\n");
  delete receiver;
}

