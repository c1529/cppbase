#include <iostream>
#include <vector>
#include <string>
#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/PatternLayout.hh>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using namespace log4cpp;
void test0(){
    PatternLayout * ptnLayout = new PatternLayout();
    ptnLayout->setConversionPattern("%d %c [%p] %m%n");//设置日志格式

    OstreamAppender * pOsApp = new OstreamAppender("console",&cout);
    pOsApp->setLayout(ptnLayout);

    Category &mycat = Category::getRoot().getInstance("salesDepart");
    mycat.setPriority(Priority::DEBUG);
    mycat.addAppender(pOsApp);

    mycat.emerg("this is an emerg message");
    mycat.fatal("this is a fatal message");
    mycat.alert("this is an alert message");
    mycat.crit("this is a crit message");
    mycat.error("this is an error message");
    mycat.warn("this is a warn message");
    mycat.info("this is an info message");
    mycat.notice("this is an notice message");
    mycat.debug("this is a debug message");

    Category::shutdown();
}
int main()
{
    test0();
    return 0;
}

