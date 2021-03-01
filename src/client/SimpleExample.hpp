
#ifndef SimpleExample_hpp
#define SimpleExample_hpp

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "dto/DTOs.hpp"

#include "./DemoApiClient.hpp"

class SimpleExample {
private:
  constexpr static const char* TAG = "SimpleExample";
public:
  
  void static runExample(const std::shared_ptr<DemoApiClient>& client) {
    
    /*  
    {
      auto data = client->styleDex_css()->readBodyToString();
      OATPP_LOGD(TAG, "[styleDex_css] data='%s'", data->c_str());
    }
     
    {
        auto jsonStr = client->detectObject(0, "Jpeg data passed to POST")->readBodyToString();
        OATPP_LOGD(TAG, "[detectObject] jsonStr = '%s'", jsonStr->c_str());
        
        auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        auto myJson = jsonObjectMapper->readFromString<oatpp::Object<ImgBoundingBoxObj>>(jsonStr);
      
        oatpp::String jsonStr_ = jsonObjectMapper->writeToString(myJson); 
        OATPP_LOGD(TAG, "[detectObject] jsonStr = %s", jsonStr_->c_str());
    }
    */
    {
        auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        
        auto response = client->detectObject(0, "Jpeg data passed to POST");
        auto myJson = response->readBodyToDto<oatpp::Object<ImgBoundingBoxObj>>(jsonObjectMapper.get());
        oatpp::String jsonStr = jsonObjectMapper->writeToString(myJson); 
        OATPP_LOGD(TAG, "[detectObject] jsonStr = %s", jsonStr->c_str());
    }
    /*  
    {
      auto data = client->doGet()->readBodyToString();
      OATPP_LOGD(TAG, "[doGet] data='%s'", data->c_str());
    }
    
    {
      auto data = client->doPost("Some data passed to POST")->readBodyToString();
      OATPP_LOGD(TAG, "[doPost] data='%s'", data->c_str());
    }
    
    {
      auto data = client->doGetAnything("path-parameter")->readBodyToString();
      OATPP_LOGD(TAG, "[doGetAnything] data='%s'", data->c_str());
    }
    
    {
      auto data = client->doPostAnything("path-parameter", "Some body here")->readBodyToString();
      OATPP_LOGD(TAG, "[doPostAnything] data='%s'", data->c_str());
    }
    
    {
      auto dto = MyRequestDto::createShared();
      dto->message = "Some message";
      dto->code = 200;
      auto data = client->doPostWithDto(dto)->readBodyToString();
      OATPP_LOGD(TAG, "[doPostWithDto] data='%s'", data->c_str());
    }
    */
  }
  
};

#endif /* SimpleExample_hpp */
