#pragma once
 
#include "log4cpp/Category.hh"
#include "log4cpp/PropertyConfigurator.hh"
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

using namespace std;

/*********************************************************************************************************/
/**                                                宏配置                                               **/
/*********************************************************************************************************/
/* 默认时间格式 */ 
#define Qlog4DefaultTimeFromat "%d{%Y-%m-%d %H:%M:%S,%l} %c-> [%6p] %x: %m%n"

/** 提供的默认日志宏 **/
#define Q_LOG_DEBUG(format, ...)   root.debug( "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_INFO(format, ...)    root.info(  "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_NOTICE(format, ...)  root.notice("[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_WARN(format, ...)    root.warn(  "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_ERROR(format, ...)   root.error( "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_CRIT(format, ...)    root.crit(  "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_ALERT(format, ...)   root.alert( "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_FATAL(format, ...)   root.fatal( "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_EMERG(format, ...)   root.emerg( "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)

/** 获取模块日志, appname 是模块名称 **/
#define Q_LOG_CREAT(appname)       root.getInstance(appname); 

/*********************************************************************************************************/
/**                                               全局变量                                              **/
/*********************************************************************************************************/
/** 全局根root 日志*/
extern log4cpp::Category& root = log4cpp::Category::getRoot();
 


/*********************************************************************************************************/
/**                                               函数开始                                              **/
/*********************************************************************************************************/
namespace log4cpp
{
    /** 自定义快速配置 */
	class LOG4CPP_EXPORT QLog4cpp
	{
    public:

        /** 先初始化 **/
        static void NewInstance() {
            try {
                log4cpp::PropertyConfigurator::configure("./log4cpp.conf");
            }
            catch (log4cpp::ConfigureFailure& f) { 
            }

            log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("console", &cout);
            log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
            pLayout->setConversionPattern(Qlog4DefaultTimeFromat); // 时间 TAG [等级] : 消息
            osAppender->setLayout(pLayout);
             
            root.addAppender(osAppender); // 最好只设置一次,否则执行 shutdown 时可能出错
              
            //root.setPriority(log4cpp::Priority::INFO); // 低于此级别的信息将不会输出
             
            //// 释放 关闭 
            //log4cpp::Category::shutdown();
        }

        /** 一定要关闭 **/
        static void Close() {
            // 释放 关闭 
            log4cpp::Category::shutdown();
        }
       
	};
}