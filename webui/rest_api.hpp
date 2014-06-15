#ifndef __CAWSTATS_WEBUI_REST_API_HPP__
#define __CAWSTATS_WEBUI_REST_API_HPP__

#include <string>
#include <cppcms/application.h>

class rest_api : public cppcms::application {
public:
    rest_api(cppcms::service &);
protected:  
    void main(std::string);
    void month(std::string, std::string);
private:

};

#endif /* __CAWSTATS_WEBUI_REST_API_HPP__ */
