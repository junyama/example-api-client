#ifndef DTOs_hpp
#define DTOs_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class BoundingBoxObj : public oatpp::DTO {

  DTO_INIT(BoundingBoxObj, DTO /* extends */)

  DTO_FIELD(Int32, sex);
  DTO_FIELD(Int32, score);
  DTO_FIELD(Int32, top);
  DTO_FIELD(Int32, left);
  DTO_FIELD(Int32, height);
  DTO_FIELD(Int32, width);
};

class ImgBoundingBoxObj : public oatpp::DTO {

  DTO_INIT(ImgBoundingBoxObj, DTO /* extends */)

  DTO_FIELD(String, img);
  DTO_FIELD(List<Object<BoundingBoxObj>>, boxList); 
};

class LutObj : public oatpp::DTO {

  DTO_INIT(LutObj, DTO /* extends */)

  DTO_FIELD(Int32, index);
  DTO_FIELD(Int32, LUT_3D_SIZE);
  DTO_FIELD(Vector<Vector<Float32>>, LUT_3D); 
};


#include OATPP_CODEGEN_END(DTO) ///< End DTO codegen section

#endif /* DTOs_hpp */
