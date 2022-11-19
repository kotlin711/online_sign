#include "ApiController.h"
#include "plugins/libsigntron.h"
#include "plugins/base64.h"
// Add definition of your processing function here


void ApiController::sign(
                    const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback,
                    std::string key,
                    std::string json,
                    int type) {

    Json::Value temp;
    json=base64_decode(json);
    if (type==1){
        std::string text =  tron_transaction_sign_trc10(json.data(),key.data());
        temp["data"]=text;
        callback(HttpResponse::newHttpJsonResponse(temp));
        return;
    } else if (type==2){
        std::string text =  tron_transaction_sign_trc20(json.data(),key.data());
        temp["data"]=text;
        callback(HttpResponse::newHttpJsonResponse(temp));
        return;
    } else{
        callback(HttpResponse::newHttpJsonResponse(temp));
        return;
    }

}
void ApiController::transfer(const HttpRequestPtr& req,
                             std::function<void (const HttpResponsePtr &)> &&callback,
                             std::string key,
                             std::string toaddress,
                             long amount,
                             int type){

    LOG_DEBUG<<type;
    Json::Value temp;
    if (type==1){
        std::string text =tron_easy_transfer(key.data(),toaddress.data(),amount);
        Json::Reader reader;
        bool parsingSuccessful = reader.parse( text, temp );
        if ( !parsingSuccessful )
        {
            callback(HttpResponse::newHttpJsonResponse(temp));
            return;
        }
        callback(HttpResponse::newHttpJsonResponse(temp));
        return;
    } else if (type==2){
        std::string text =  tron_easy_transfer_usdt(key.data(),toaddress.data(),amount);
        Json::Reader reader;
        bool parsingSuccessful = reader.parse( text, temp );
        if ( !parsingSuccessful )
        {
            callback(HttpResponse::newHttpJsonResponse(temp));
            return;
        }
        callback(HttpResponse::newHttpJsonResponse(temp));
        return;
    } else{
        callback(HttpResponse::newHttpJsonResponse(temp));
        return;
    }
}
