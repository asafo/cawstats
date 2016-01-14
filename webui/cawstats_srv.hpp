#ifndef __CAWSTATS_WEBUI_CAWSTATS_SRV_HPP__
#define __CAWSTATS_WEBUI_CAWSTATS_SRV_HPP__

#include <cppcms/application.h>  
#include <cppcms/service.h>

#define STAND_ALONE

class cawstats_srv : public cppcms::application {  
public:  
    cawstats_srv(cppcms::service&);
    void home(std::string);
    void main(std::string);
#ifdef STAND_ALONE
    void js(std::string);
    void css(std::string, std::string);
    void image(std::string, std::string);
    void serve_file(std::string file_name, std::string content_type);
#endif
private:
    std::string _static_prefix;
};  

#endif /* __CAWSTATS_WEBUI_CAWSTATS_SRV_HPP__*/
