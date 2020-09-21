// Qlog4c.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 
#include <log4cpp/Qlog4cpp/qlog4cpp.h> 
 

/**
* Qlog 快速配置
*/
void QlogTest() {
  
    // 根日志
    Q_LOG_DEBUG("测试日志%d", 1);
    Q_LOG_INFO("测试日志%d", 2);
    Q_LOG_NOTICE("测试日志%d", 3);
    Q_LOG_WARN("测试日志%d", 4);
    Q_LOG_ERROR("测试日志%d", 5);
    Q_LOG_FATAL("测试日志%d", 6);

    // 模块1的Log
    log4cpp::Category& info = Q_LOG_CREAT("app1");
    info.debug("system is running %s", "日志");
    info.info("system is running %s", "日志trst");
    info.warn("system has a warning");
    info.error("system has a error, can't find a file");
    info.fatal("system has a fatal error,must be shutdown"); 

    // 模块2的Log
    log4cpp::Category& warn = Q_LOG_CREAT("app2");
    warn.debug("2system is running");
    warn.info("2system is running");
    warn.warn("2system has a warning");
    warn.error("2system has a error, can't find a file");
    warn.fatal("2system has a fatal error,must be shutdown"); 

    log4cpp::Category& app3 = Q_LOG_CREAT("app3");
    app3.debug("2system is running");
    app3.info("2system is running");
    app3.warn("2system has a warning");
    app3.error("2system has a error, can't find a file");
    app3.fatal("2system has a fatal error,must be shutdown");
    
}

int main(int argc, char* argv[]) {
 
    printf("ceshi1");
    log4cpp::QLog4cpp::NewInstance();
    QlogTest();
    log4cpp::QLog4cpp::Close();
   
	return 0;
}