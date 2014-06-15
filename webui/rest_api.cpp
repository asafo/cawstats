#include "rest_api.hpp"

#include "../include/file.hpp"

#include <cppcms/url_dispatcher.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/http_file.h>

using namespace cawstats;

rest_api::rest_api(cppcms::service& srv) : cppcms::application(srv)
{ 
    dispatcher().assign("/month/([0-9]*)/([0-9]*)/", &rest_api::month, this, 1, 2);
}

void rest_api::month(std::string year, std::string month) 
{
}

void rest_api::main(std::string url)
{
    /*    std::cout<<"main in rest api "<<url<<std::endl;
    std::cout<<"query string "<<request().query_string()<<std::endl;
    std::cout<<"method : "<<request().request_method()<<std::endl;*/
    cppcms::application::main(url);
}
