#include "InsertCtrl.h"
#include <iostream>

void InsertCtrl::asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    std::string userid = "testuser4"; // Length 9
    std::string knowledge = "";
    /* If userid_length + knowledge_length exceeds 393,166, the query will hang*/
    const int knowledge_param_length = 393156; // Increasing this by 1 fails (>= 393157) (>= 393166 total param size()).
    for (int i = 0; i < knowledge_param_length; i++)
    {
        knowledge += "a";
    }
    std::cout << "KNOWLEDGE SIZE: " << knowledge.size() + userid.size() << std::endl;

    auto clientPtr = drogon::app().getDbClient("psql");
    auto f = clientPtr->execSqlAsyncFuture("INSERT INTO public.knowledge (userid, knowledge) VALUES ($1, $2)", userid, knowledge);
    auto result = f.get(); // Block until we get the result or catch the exception;

    std::cout << result.affectedRows() << " rows updated!" << std::endl;
    auto resp = drogon::HttpResponse::newHttpResponse();
    resp->setStatusCode(drogon::k200OK);
    callback(resp);
}
