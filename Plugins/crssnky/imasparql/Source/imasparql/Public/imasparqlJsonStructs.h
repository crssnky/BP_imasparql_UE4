#pragma once

#include "CoreMinimal.h"
#include "Math/TransformCalculus2D.h"	// For"cereal-UE4.hxx"
#include "Serialization/JsonSerializerMacros.h"

#include "cereal/cereal.hpp"
#include "cereal/archives/json.hpp"
#include "cereal-UE4.hxx"
#include <sstream>

#include "imasparqlJsonStructs.generated.h"


USTRUCT(BlueprintType)
struct FIdol{
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString alternateName;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString birthDate;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString birthPlace;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString description;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString familyName;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString gender;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString givenName;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		float height;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		TArray<FString> memberOf;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString name;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		TArray<FString> own;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		float weight;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		int32 age;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString attribute;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString bloodType;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		float bust;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString category;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString color;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString constellation;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString division;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		TArray<FString> favorite;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString handedness;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		float hip;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		TArray<FString> hobby;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		float shoeSize;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		TArray<FString> talent;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString title;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		float waist;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString alternateNameKana;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString cv;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString familyNameKana;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString givenNameKana;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString nameKana;

	FIdol():
		alternateName(""),
		birthDate(""),
		birthPlace(""),
		description(""),
		familyName(""),
		gender(""),
		givenName(""),
		height(0.0f),
		name(""),
		weight(0.0f),
		age(0),
		attribute(""),
		bloodType(""),
		bust(0.0f),
		category(""),
		color(""),
		constellation(""),
		division(""),
		handedness(""),
		hip(0.0f),
		shoeSize(0.0f),
		title(""),
		waist(0.0f),
		alternateNameKana(""),
		cv(""),
		familyNameKana(""),
		givenNameKana(""),
		nameKana(""),
		hobby(),
		favorite(),
		talent(),
		memberOf(),
		own(){}
};

template<class A, class T>
static void OptionalField(A &a, const std::string &name, T &t){
	try{
		a(cereal::make_nvp(name, t));
	} catch(std::exception &e){
		(void)e;
	}
}
USTRUCT(BlueprintType)
struct FimasparqlResultUnit{
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString type;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString datatype;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString xml_lang;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FString value;
};
template<typename T>
void serialize(T& a, FimasparqlResultUnit& in){
	OptionalField(a, "datatype", in.datatype);
	OptionalField(a, "xml:lang", in.xml_lang);
	a(
		cereal::make_nvp("type", in.type),
		//cereal::make_nvp("datatype", in.datatype),
		//cereal::make_nvp("xml:lang", in.xml_lang),
		cereal::make_nvp("value", in.value)
	);
}
USTRUCT(BlueprintType)
struct FimasparqlBindings{
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FimasparqlResultUnit predicate;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FimasparqlResultUnit object;
};
template<typename T>
void serialize(T& a, FimasparqlBindings& in){
	a(
		cereal::make_nvp("predicate", in.predicate),
		cereal::make_nvp("object", in.object)
	);
}
USTRUCT(BlueprintType)
struct FimasparqlResult{
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		TArray<FimasparqlBindings> bindings;
};
template<typename T>
void serialize(T& a, FimasparqlResult& in){
	a(
		cereal::make_nvp("bindings", in.bindings)
	);
}
USTRUCT(BlueprintType)
struct FimasparqlHead{
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		TArray<FString> vars;
};
template<typename T>
void serialize(T& a, FimasparqlHead& in){
	a(
		cereal::make_nvp("vars", in.vars)
	);
}
USTRUCT(BlueprintType)
struct FimasparqlJSON{
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FimasparqlResult results;
};
template<typename T>
void serialize(T& a, FimasparqlJSON& in){
	a(
		cereal::make_nvp("results", in.results)
	);
}
