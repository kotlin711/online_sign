#include "ViewController.h"
#include "plugins/Constant.h"
// Add definition of your processing function here
void ViewController::index(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {

    Json::Value temp;
    HttpViewData data;
    data.insert("start_time",std::string(start_time));
    data.insert("count",std::to_string(num));
    auto resp=HttpResponse::newHttpViewResponse("home.csp",data);
    callback(resp);
}
