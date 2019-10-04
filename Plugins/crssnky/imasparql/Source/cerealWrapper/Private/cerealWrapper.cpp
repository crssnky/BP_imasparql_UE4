#include "cerealWrapper.h"

#include "cereal/archives/json.hpp"
#include "Math/TransformCalculus2D.h"	// For"cereal-UE4.hxx"
#include "cereal-UE4.hxx"
#include "imasparqlJsonStructs.h"

#include "Modules/ModuleManager.h"

template<typename T>
cereal::NameValuePair<T> make_nvp(const char* name, T&& value)
{
	return cereal::make_nvp(name, value);
}

template<typename T>
cereal::NameValuePair<T> make_nvp(std::string const& name, T&& value)
{
	return cereal::make_nvp(name, value);
}

//template <typename T, typename U>
//FORCEINLINE void createJSONInputArchive(std::stringstream& arg, T& t, U& u)
//{
//	cereal::JSONInputArchive a(arg);
//	a(t, u);
//}

//template void createJSONInputArchive<FimasparqlHead, FimasparqlResult>(std::stringstream&, FimasparqlHead&, FimasparqlResult&);

void createJSONInputArchive(std::stringstream& arg, FimasparqlHead& t, FimasparqlResult& u)
{
	cereal::JSONInputArchive a(arg);
	a(t, u);
}

IMPLEMENT_MODULE(FDefaultModuleImpl, cerealWrapper);
