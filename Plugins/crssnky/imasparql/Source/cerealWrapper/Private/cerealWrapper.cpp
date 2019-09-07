#include "cerealWrapper.h"

#include "cereal/cereal.hpp"
#include "cereal/archives/json.hpp"

#include "Modules/ModuleManager.h"


//template<typename T>
//static cereal::NameValuePair<T> FcerealWrapper::make_nvp(const char* name, T&& value)
//{
//	return cereal::make_nvp(name, value);
//}
//
//template<typename T>
//static cereal::NameValuePair<T> FcerealWrapper::make_nvp(std::string const& name, T&& value)
//{
//	return cereal::make_nvp(name, value);
//}


IMPLEMENT_MODULE(FDefaultModuleImpl, cerealWrapper);

