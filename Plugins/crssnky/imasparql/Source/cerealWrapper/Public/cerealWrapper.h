#pragma once

#include <string>
#include <sstream>
#include "CoreMinimal.h"

namespace cereal {
	template<typename T>
	class NameValuePair;
}
struct FimasparqlHead;
struct FimasparqlResult;

template <typename T>
CEREALWRAPPER_API cereal::NameValuePair<T> make_nvp(const char* name, T&& value);
template <typename T>
CEREALWRAPPER_API cereal::NameValuePair<T> make_nvp(std::string const& name, T&& value);
//template <typename T, typename U>
//CEREALWRAPPER_API  void createJSONInputArchive(std::stringstream& arg, T& t, U& u);
CEREALWRAPPER_API  void createJSONInputArchive(std::stringstream& arg, FimasparqlHead& t, FimasparqlResult& u);

