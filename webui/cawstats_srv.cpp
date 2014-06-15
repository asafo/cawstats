#include "cawstats_srv.hpp"

#include "../config.hpp"

#include "content/general.hpp"

#include "rest_api.hpp"

#include <cppcms/http_response.h>  
#include <cppcms/url_dispatcher.h>  
#include <cppcms/url_mapper.h>  

#include <fstream>
#include <string> 

#define STAND_ALONE

using std::string;

cawstats_srv::cawstats_srv(cppcms::service& srv): cppcms::application(srv)
{

#ifdef STAND_ALONE
    // static files (development, stand alone) : 
    dispatcher().assign("/([A-Za-z\\-]*)/(.*\\.js)", &cawstats_srv::js, this, 1, 2);
    dispatcher().assign("/([A-Za-z\\-]*)/(.*\\.css)", &cawstats_srv::css, this, 1, 2);
    dispatcher().assign("/([A-Za-z\\-]*)/(.*\\.png)", &cawstats_srv::image, this, 1, 2);
#endif

    attach(new rest_api(srv),  "/api",  "api/{1}", // mapping  
	   "api/(/.*)", 1);   // dispatching 

    dispatcher().assign("/", &cawstats_srv::home, this, 1);  
    mapper().root("/");	    
}

void cawstats_srv::home(std::string)
{
    content::general info;

    info.total_visits = 1000;
    info.total_unique = 300;

    std::cout<<"cawstats_srv::home"<<std::endl;

    render("home", info);
}

void cawstats_srv::main(std::string url)
{
    /*    std::cout<<"main in celsius_srv "<<url<<std::endl;
    std::cout<<"prefix = "<<_app_prefix<<std::endl;
    std::cout<<"query string "<<request().query_string()<<std::endl;
    std::cout<<"method : "<<request().request_method()<<std::endl;*/
    cppcms::application::main(url);
}

#ifdef STAND_ALONE
void cawstats_srv::js(std::string path, std::string url)
{
    serve_file(path + "/" + url, "application/javascript");
}

void cawstats_srv::css(std::string path, std::string url)
{
    serve_file(path + "/" + url, "text/css");
}

void cawstats_srv::image(std::string path, std::string url)
{
    serve_file(path + "/" + url, "image");
}

void cawstats_srv::serve_file(std::string file_name, std::string content_type)
{
    std::ifstream f(file_name.c_str());
    if(!f) {
	std::cout<<"serve_file : not found -> "<<file_name<<std::endl;
	response().status(404);
    }
    else {
	response().content_type(content_type);
	response().out() << f.rdbuf();
    }
}
#endif

