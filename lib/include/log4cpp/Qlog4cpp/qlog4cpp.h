#pragma once
 
#include "log4cpp/Category.hh"
#include "log4cpp/PropertyConfigurator.hh"
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

using namespace std;

/*********************************************************************************************************/
/**                                                ������                                               **/
/*********************************************************************************************************/
/* Ĭ��ʱ���ʽ */ 
#define Qlog4DefaultTimeFromat "%d{%Y-%m-%d %H:%M:%S,%l} %c-> [%6p] %x: %m%n"

/** �ṩ��Ĭ����־�� **/
#define Q_LOG_DEBUG(format, ...)   root.debug( "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_INFO(format, ...)    root.info(  "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_NOTICE(format, ...)  root.notice("[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_WARN(format, ...)    root.warn(  "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_ERROR(format, ...)   root.error( "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_CRIT(format, ...)    root.crit(  "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_ALERT(format, ...)   root.alert( "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_FATAL(format, ...)   root.fatal( "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define Q_LOG_EMERG(format, ...)   root.emerg( "[%s:%-6d] " format "", __FUNCTION__ , __LINE__, ##__VA_ARGS__)

/** ��ȡģ����־, appname ��ģ������ **/
#define Q_LOG_CREAT(appname)       root.getInstance(appname); 

/*********************************************************************************************************/
/**                                               ȫ�ֱ���                                              **/
/*********************************************************************************************************/
/** ȫ�ָ�root ��־*/
extern log4cpp::Category& root = log4cpp::Category::getRoot();
 


/*********************************************************************************************************/
/**                                               ������ʼ                                              **/
/*********************************************************************************************************/
namespace log4cpp
{
    /** �Զ���������� */
	class LOG4CPP_EXPORT QLog4cpp
	{
    public:

        /** �ȳ�ʼ�� **/
        static void NewInstance() {
            try {
                log4cpp::PropertyConfigurator::configure("./log4cpp.conf");
            }
            catch (log4cpp::ConfigureFailure& f) { 
            }

            log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("console", &cout);
            log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
            pLayout->setConversionPattern(Qlog4DefaultTimeFromat); // ʱ�� TAG [�ȼ�] : ��Ϣ
            osAppender->setLayout(pLayout);
             
            root.addAppender(osAppender); // ���ֻ����һ��,����ִ�� shutdown ʱ���ܳ���
              
            //root.setPriority(log4cpp::Priority::INFO); // ���ڴ˼������Ϣ���������
             
            //// �ͷ� �ر� 
            //log4cpp::Category::shutdown();
        }

        /** һ��Ҫ�ر� **/
        static void Close() {
            // �ͷ� �ر� 
            log4cpp::Category::shutdown();
        }
       
	};
}