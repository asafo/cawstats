#include "cawstats_srv.hpp"

#include <cppcms/applications_pool.h>

int main(int argc,char ** argv)  
{  
    try {  
	cppcms::service srv(argc,argv);  
	srv.applications_pool().mount( cppcms::applications_factory<cawstats_srv>()  
					);  	
	srv.run();  
    }  
    catch(std::exception const &e) {  
        std::cerr << e.what() << std::endl;  
    }  
    
}
