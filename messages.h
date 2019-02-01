#include <iostream>



void ms_error(int number, std::string description, bool pause = 0)
{
    std::cout<<"ERROR: "<<number<<"\n";
    std::cout<<description<<"\n";

}

void ms_message(std::string description, bool pause = 0)
{
    std::cout<<"MESSAGE:\n";
    std::cout<<description<<"\n";

}
