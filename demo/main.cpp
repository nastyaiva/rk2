#include "../Command.cpp"
int main()
{
  ConcreteCommand command( new Receiver() );
  
  Invoker invoker;
  invoker.set( &command );
  invoker.confirm();
  
  return 0;
}
