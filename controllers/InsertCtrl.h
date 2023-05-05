#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class InsertCtrl : public drogon::HttpSimpleController<InsertCtrl>
{
public:
  void asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) override;
  PATH_LIST_BEGIN
  // list path definitions here;
  PATH_ADD("/insert", Post);
  PATH_LIST_END
};
