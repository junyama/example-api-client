
#ifndef SimpleExample_cpp
#define SimpleExample_cpp
#define SERVER_ADDRESS "localhost"
#define SERVER_PORT_NUMBER 8000

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "dto/DTOs.hpp"

#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp/network/tcp/client/ConnectionProvider.hpp"

#include "./DemoApiClient.hpp"

using namespace oatpp::network;
using namespace oatpp::web;
using namespace oatpp::parser;


class SimpleExample {
private:
  constexpr static const char* TAG = "SimpleExample";
  std::shared_ptr<DemoApiClient> client;
    
public:
   oatpp::String bodyStr;
    
   void createClient() {
        auto connectionProvider = tcp::client::ConnectionProvider::createShared({SERVER_ADDRESS, SERVER_PORT_NUMBER});
        auto requestExecutor = client::HttpRequestExecutor::createShared(connectionProvider);
        auto objectMapper = json::mapping::ObjectMapper::createShared();
        client = DemoApiClient::createShared(requestExecutor, objectMapper);

        //runExample();
  }
  
  void runExample() {
    //OATPP_LOGD(TAG, "runExample called");
    {
        bodyStr = client->detectObject(0, "Jpeg data passed to POST")->readBodyToString();
        OATPP_LOGD(TAG, "[detectObject] bodyStr = '%s'", bodyStr->c_str());
        
        auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        auto myJson = jsonObjectMapper->readFromString<oatpp::Object<ImgBoundingBoxObj>>(bodyStr);
      
        bodyStr = jsonObjectMapper->writeToString(myJson); 
        OATPP_LOGD(TAG, "[detectObject] bodyStr = %s", bodyStr->c_str());
    }
    //
    {
        auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        
        auto response = client->detectObject(0, "Jpeg data passed to POST");
        auto myJson = response->readBodyToDto<oatpp::Object<ImgBoundingBoxObj>>(jsonObjectMapper.get());
        oatpp::String jsonStr = jsonObjectMapper->writeToString(myJson); 
        OATPP_LOGD(TAG, "[detectObject] jsonStr = %s", jsonStr->c_str());
    }
   
  }
  
};

#endif /* SimpleExample_cpp */
