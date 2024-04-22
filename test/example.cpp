
#include<iostream>

#include"mal_log.hpp"
#include"timestamp.hpp"
int main()
{
    int tm = mal::get_ns_timestamp();
    std::cout<< "tm = "<<tm<< std::endl;
	return 0;
}
