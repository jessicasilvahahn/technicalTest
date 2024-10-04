#include "Session.hpp"

Session::Session(std::shared_ptr<DataReceiver> dataReceiver)
    : dataReceiver_(dataReceiver)
    {}

void Session::start()
{
    dataReceiver_->receive(); //Start receiving data
}