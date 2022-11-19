/**
 *
 *  ApiFilter.cc
 *
 */

#include "ApiFilter.h"
#include "plugins/Constant.h"
using namespace drogon;

void ApiFilter::doFilter(const HttpRequestPtr &req,
                         FilterCallback &&fcb,
                         FilterChainCallback &&fccb) {

    if (map.count(req->getParameter("token")) > 0) {
        map[req->getParameter("token")]=   map[req->getParameter("token")]--;
        fccb();
        return;
    } else {
        if (num > 0) {
            num--;
            fccb();
            return;
        } else {
            auto res = drogon::HttpResponse::newHttpResponse();
            res->setStatusCode(k403Forbidden);
            fcb(res);
            return;
        }
    }

}
