#pragma once

#include <string>
#include <sstream>
#include "CoreMinimal.h"
#include "cereal/cereal.hpp"
#include "cereal/archives/json.hpp"

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


