#pragma once

#include <string>
#include <sstream>
#include "CoreMinimal.h"

namespace cereal {
	template<typename T>
	class NameValuePair;

	template<typename T>
	NameValuePair<T> make_nvp(const char* name, T&& value);
	template<typename T>
	NameValuePair<T> make_nvp(std::string const& name, T&& value);
}

class CEREALWRAPPER_API FcerealWrapper {
public:
	template <typename T>
	static cereal::NameValuePair<T> make_nvp(const char* name, T&& value)
	{
		return cereal::make_nvp(name, value);
	}
	template <typename T>
	static cereal::NameValuePair<T> make_nvp(std::string const& name, T&& value)
	{
		return cereal::make_nvp(name, value);
	}
};


