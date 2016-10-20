/**
 * create: 2016-10-10
 * author: mr.wclong@yahoo.com
 */
#ifndef MODULE_HELLO_HPP
#define MODULE_HELLO_HPP
#include "../handler.hpp"

using namespace coh;

class hello_module : public module_handler {
public:
    hello_module(http_service::options option);
    int  handle_events();
    const char* path() const;
    const char* name() const;
    void on_request_header(conid_t              cid,
                           txnid_t              tid,
                           const http_request&  req,
                           http_response*       rsp);
private:
    http_service::options option_;
};

extern "C" module_handler* create_module(http_service::options option)
{
    return new hello_module(option);
}

#endif