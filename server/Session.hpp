#ifndef SESSION_H
#define SESSION_H

#include <boost/asio.hpp>
#include <memory>
#include <string>
#include "DataReceiver.hpp"

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    
    explicit Session(std::shared_ptr<DataReceiver> dataReceiver);
    void start();

private:
    std::shared_ptr<DataReceiver> dataReceiver_;
};

#endif