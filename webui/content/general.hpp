#ifndef __CAWSTATS_WEBUI_CONTENT_GENERAL_HPP__
#define __CAWSTATS_WEBUI_CONTENT_GENERAL_HPP__


#include <cppcms/view.h>  
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace content {
    struct general : public cppcms::base_content {
	boost::posix_time::ptime first_time;
	boost::posix_time::ptime last_time;
	boost::posix_time::ptime last_update;
	int total_visits;
	int total_unique;
    };  
}
  
#endif /* __CAWSTATS_WEBUI_CONTENT_GENERAL_HPP__ */
