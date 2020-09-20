// Qlog4c.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 
#include <log4cpp/Qlog4cpp/qlog4cpp.h> 

using namespace std;

/**
* Qlog 快速配置
*/
void QlogInit() {
    try {
        log4cpp::PropertyConfigurator::configure("./log4cpp.conf");
    }
    catch (log4cpp::ConfigureFailure& f) {

    }

    log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender", &cout);
    log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
    pLayout->setConversionPattern("%d{%Y-%m-%d %H:%M:%S,%l} %c-> [%5p] %x: %m%n"); // 时间 TAG [等级] : 消息
    osAppender->setLayout(pLayout);
   // osAppender->getName("");
    // 根日志
    log4cpp::Category& root = log4cpp::Category::getRoot();
    root.addAppender(osAppender); // 最好只设置一次,否则执行 shutdown 时可能出错
    root.debug("system is running");
    root.info("system is running");
    root.warn("system has a warning");
    root.error("system has a error, can't find a file");
    root.fatal("system has a fatal error,must be shutdown"); 

    // 模块1的Log
    log4cpp::Category& info = root.getInstance("console");
   // info.setPriority(log4cpp::Priority::INFO); // 低于此级别的信息将不会输出
    info.debug("system is running");
    info.info("system is running");
    info.warn("system has a warning");
    info.error("system has a error, can't find a file");
    info.fatal("system has a fatal error,must be shutdown"); 

    // 模块2的Log
    log4cpp::Category& warn = root.getInstance("app2");
  // warn.setPriority(log4cpp::Priority::WARN); // 低于此级别的信息将不会输出
    warn.debug("2system is running");
    warn.info("2system is running");
    warn.warn("2system has a warning");
    warn.error("2system has a error, can't find a file");
    warn.fatal("2system has a fatal error,must be shutdown"); 
     
    // 释放 关闭 
    log4cpp::Category::shutdown();
}

int main(int argc, char* argv[]) {

    QlogInit();

	return 0;
}