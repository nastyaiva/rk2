#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "./../Command.cpp"

// Custom stdout capture class
class StdoutCapture {
private:
    std::stringstream buffer;
    std::streambuf* original;

public:
    StdoutCapture() : original(std::cout.rdbuf()) {
        std::cout.rdbuf(buffer.rdbuf());
    }

    ~StdoutCapture() {
        std::cout.rdbuf(original);
    }

    std::string getOutput() {
        return buffer.str();
    }
};

// Test case to check if the receiver performs the action correctly
TEST(CommandPatternTest, ReceiverAction) {
  Receiver receiver;
  StdoutCapture capture;
  receiver.action();
  std::string output = capture.getOutput();


  ASSERT_EQ(output, "Receiver: execute action\n");
}

// Test case to check if the concrete command executes correctly
TEST(CommandPatternTest, CommandExecute) {
  Receiver *receiver = new Receiver();
  ConcreteCommand command(receiver);
  StdoutCapture capture;
  command.execute();
  std::string output = capture.getOutput();

  ASSERT_EQ(output, "Receiver: execute action\n");
}

// Test case to check if the invoker confirms the command action
TEST(CommandPatternTest, InvokerConfirm) {
  Receiver *receiver = new Receiver();
  ConcreteCommand command(receiver);
  Invoker invoker;
  invoker.set(&command);
  StdoutCapture capture;
  invoker.confirm();
  std::string output = capture.getOutput();

  ASSERT_EQ(output, "Receiver: execute action\n");
}


