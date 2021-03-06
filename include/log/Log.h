// **********************************************************************
// This file was generated by a TAF parser!
// TAF version 4.6.0 by WSRD Tencent.
// Generated from `Log.jce'
// **********************************************************************

#ifndef __LOG_H_
#define __LOG_H_

#include <map>
#include <string>
#include <vector>
#include "jce/Jce.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"


namespace taf
{

    /* callback of async proxy for client */
    class LogPrxCallback: public taf::ServantProxyCallback
    {
    public:
        virtual ~LogPrxCallback(){}
        virtual void callback_logger()
        { throw std::runtime_error("callback_logger() overloading incorrect."); }
        virtual void callback_logger_exception(taf::Int32 ret)
        { throw std::runtime_error("callback_logger_exception() overloading incorrect."); }

    public:
        int onDispatch(taf::ReqMessagePtr msg);
    };
    typedef taf::TC_AutoPtr<LogPrxCallback> LogPrxCallbackPtr;

    /* proxy for client */
    class LogProxy : public taf::ServantProxy
    {
    public:
        typedef map<string, string> TAF_CONTEXT;
        void logger(const std::string & app,const std::string & server,const std::string & file,const std::string & format,const vector<std::string> & buffer,const map<string, string> &context = TAF_CONTEXT());
        void async_logger(LogPrxCallbackPtr callback,const std::string & app,const std::string & server,const std::string & file,const std::string & format,const vector<std::string> & buffer,const map<string, string> &context = TAF_CONTEXT());

        LogProxy* taf_hash(int64_t key);
    };
    typedef taf::TC_AutoPtr<LogProxy> LogPrx;

    /* servant for server */
    class Log : public taf::Servant
    {
    public:
        virtual ~Log(){}
        virtual void logger(const std::string & app,const std::string & server,const std::string & file,const std::string & format,const vector<std::string> & buffer,taf::JceCurrentPtr current) = 0;
        static void async_response_logger(taf::JceCurrentPtr current);

    public:
        int onDispatch(taf::JceCurrentPtr _current, vector<char> &_sResponseBuffer);
    };


}



#endif
