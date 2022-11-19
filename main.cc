#include <drogon/drogon.h>
#include "plugins//Constant.h"
int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0",8080);
    std::thread([]{
        while (1){
            std::this_thread::sleep_for(std::chrono::hours (24));
        }
    }).detach();
    //Load config file
//    drogon::app().loadConfigFile("../config.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
