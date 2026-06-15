#include <string>
#include <iomanip>
#include "log4cpp/PropertyConfigurator.hh"
#include "log4cpp/Category.hh"
 
int main()
{
    try
    {
      log4cpp::PropertyConfigurator::configure("./cfg/log4cfg");
    }
    catch (log4cpp::ConfigureFailure& f)
    {
        std::cerr << "configure problem " << f.what() << std::endl;
        
    }
    log4cpp::Category & log = log4cpp::Category::getRoot();
 
    std::string s = __FILE__;
    s += " : ";
    std::ostringstream line;
    line << std::setw(4) << std::setfill('0') << __LINE__;
    s += line.str();
    s += " : ";
    std::ostringstream  buf;
    buf<< "test message"; ;
    s += buf.str();
 
    log.info(s);
}
