/*
* Author: Sharath Lokesh
*/
#include "Logger.h"

void test_case_1(Logger *log)
{   
    std::cout<< "\n************ Test Case 1: testing set level ************" << std::endl;
    log->Info("says Hi!");
    log->Warn("says Hey!");
    log->Debug("says Hello!");
}

void test_case_2(Logger *log)
{   
    
    std::cout<< "\n************ Test Case 2: passing of variables ************" << std::endl;
    for (int i = 0; i < 2; i++)
        log->Info("Value of i is: ", i);
    const char* message = "This is a test message for test case 2";
    log->Warn(message);
    # define pi 3.1425
    log->Debug("Vlaue of pi is: ", pi);
}

void test_error(Logger *log)
{
    std::cout<< "\n************ Test Case 3: testing for error statements ************" << std::endl;
    int j = -1;
    log->Error("says FATAL!!!", "Testing Error Message: ", j);
}
int main(int argc, char* argv[])
{
    Logger logger;
    
    //default action
    test_case_1(&logger);
    
    //INFO
    logger.SetLevel('i');
    test_case_1(&logger);
    
    //INFO, WARN
    logger.SetLevel('w');
    test_case_1(&logger);
    
    //INFO, WARN, DEBUG
    logger.SetLevel('d');
    test_case_1(&logger);

    test_case_2(&logger);

    test_error(&logger);

    std::cout << "Hello, World!" << std::endl;
    
    
    return 0;
}