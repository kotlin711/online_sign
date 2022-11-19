#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class ApiController : public drogon::HttpController<ApiController>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
        ADD_METHOD_TO(ApiController::sign, "/api/sign?key={1}&json={2}&type={3}", Get,"ApiFilter"); // path is /ApiController/{arg2}/{arg1}
        ADD_METHOD_TO(ApiController::transfer, "/api/transfer?key={1}&toaddress={2}&amount={3}&type={4} ", Get,"ApiFilter"); // path is /ApiController/{arg1}/{arg2}/list
    // ADD_METHOD_TO(ApiController::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
     void sign(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback,  std::string key ,std::string json,int type=0);
    void transfer(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback,   std::string key ,std::string toaddress,long amount,int type=0);

    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;

};
