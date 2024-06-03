/*
 * Author: Sharath Lokesh
 */
#include "Logger.h"

void test_case(Logger *log)
{
    log->Info("This is an informational message");
    log->Warn("This is a warning message");
    log->Debug("This is a debug message");
}
int main(int argc, char* argv[])
{
    Logger logger;
    
    //default action
    test_case(&logger);
    
    //INFO
    logger.SetLevel('i');
    test_case(&logger);
    
    //INFO, WARN
    logger.SetLevel('w');
    test_case(&logger);
    
    //INFO, WARN, DEBUG
    logger.SetLevel('d');
    test_case(&logger);
    
    
    return 0;
}