#pragma once

#include "CoreMinimal.h"
#include "Math/TransformCalculus2D.h"	// For"cereal-UE4.hxx"
#include "Serialization/JsonSerializerMacros.h"

#include "cereal/cereal.hpp"
#include "cereal/archives/json.hpp"
#include "cereal-UE4.hxx"
#include <sstream>

#include "imasparqlJsonStructs.generated.h"


//USTRUCT(BlueprintType)
//enum class EConstellation{
//	Aries = 0,
//	Taurus,
//	Gemini,
//	Cancer,
//	Leo,
//	Virgo,
//	Libra,
//	Scorpio,
//	Sagittarius,
//	Capricorn,
//	Aquarius,
//	Pisces
//};
//const FString Constellations[] = {
//	"牡羊座",
//	"牡牛座",
//	"双子座",
//	"蟹座",
//	"獅子座",
//	"乙女座",
//	"天秤座",
//	"蠍座",
//	"射手座",
//	"山羊座",
//	"水瓶座",
//	"魚座"
//};
//USTRUCT(BlueprintType)
//enum class EHandedness{
//	right = 0,
//	left,
//	both
//};
//const FString Handednesses[] = {
//	"右利き",
//	"左利き",
//	"両利き"
//};
//USTRUCT(BlueprintType)
//enum class EGender{
//	male = 0,
//	female
//};
//const FString genderes[] = {
//	"male",
//	"female"
//};
//USTRUCT(BlueprintType)
//enum class ETitle{
//	_765AS = 0,
//	_961ProIdols,
//	DearlyStars,
//	CinderellaGirls,
//	MillionStars,
//	_315ProIdols,
//	_283ProIdols
//};
//const FString Titles[] = {
//	"765AS",
//	"961ProIdols",
//	"DearlyStars",
//	"CinderellaGirls",
//	"MillionStars",
//	"315ProIdols",
//	"283ProIdols"
//};
//USTRUCT(BlueprintType)
//enum class EBloodType{
//	A = 0,
//	B,
//	O,
//	AB
//};
//const FString BloodTypes[] = {
//	"A",
//	"B",
//	"O",
//	"AB"
//};
//USTRUCT(BlueprintType)
//enum class EAttribute{
//	Vo = 0,
//	Da,
//	Vi
//};
//const FString Attributes[] = {
//	"Vo",
//	"Da",
//	"Vi"
//};
//USTRUCT(BlueprintType)
//enum class ECategory{
//	Mental = 0,
//	Physical,
//	Intelligence
//};
//const FString Categories[] = {
//	"Mental",
//	"Physical",
//	"Intelligence"
//};
//USTRUCT(BlueprintType)
//enum class EDivision{
//	Princess = 0,
//	Fairy,
//	Angel
//};
//const FString Divisions[] = {
//	"Princess",
//	"Fairy",
//	"Angel"
//};

struct FMemberOf:FJsonSerializable{
	FString memberOf;
	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE("memberOf", memberOf);
	END_JSON_SERIALIZER
		FMemberOf():memberOf(""){}
};
struct FOwn:FJsonSerializable{
	FString own;
	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE("own", own);
	END_JSON_SERIALIZER
		FOwn():own(""){}
};
struct FFavorite:FJsonSerializable{
	FString favorite;
	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE("favorite", favorite);
	END_JSON_SERIALIZER
		FFavorite():favorite(""){}
};
struct FHobby:FJsonSerializable{
	FString hobby;
	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE("hobby", hobby);
	END_JSON_SERIALIZER
		FHobby():hobby(""){}
};
struct FTalent:FJsonSerializable{
	FString talent;
	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE("talent", talent);
	END_JSON_SERIALIZER
		FTalent():talent(""){}
};

struct FJsonString:FJsonSerializable{
	FString string;
	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE("string", string);
	END_JSON_SERIALIZER
		FJsonString():string(""){}
};
struct Fbinding:FJsonSerializable{
	FString predicate;
	FString object;
	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE("predicate", predicate);
	JSON_SERIALIZE("object", object);
	END_JSON_SERIALIZER
		Fbinding():predicate(""), object(""){}
};
struct Fresults:FJsonSerializable{
	TArray<Fbinding> binding;
	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE_ARRAY_SERIALIZABLE("binding", binding, Fbinding);
	END_JSON_SERIALIZER
		Fresults():binding(){}
};
struct Fvars:FJsonSerializable{
	TArray<FJsonString> var;
	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE_ARRAY_SERIALIZABLE("var", var, FJsonString);
	END_JSON_SERIALIZER
		Fvars():var(){}
	struct Fbinding:FJsonSerializable{
		FString predicate;
		FString object;
		BEGIN_JSON_SERIALIZER
			JSON_SERIALIZE("predicate", predicate);
		JSON_SERIALIZE("object", object);
		END_JSON_SERIALIZER
			Fbinding():predicate(""), object(""){}
	};
};
struct Fhead:FJsonSerializable{
	TArray<Fresults> result;
	TArray<Fvars> vars;
	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE_ARRAY_SERIALIZABLE("binding", result, Fresults);
	JSON_SERIALIZE_ARRAY_SERIALIZABLE("vars", vars, Fvars);
	END_JSON_SERIALIZER
		Fhead():result(), vars(){}
};
struct Froot:FJsonSerializable{
	TArray<Fhead> head;
	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE_ARRAY_SERIALIZABLE("", head, Fhead);
	END_JSON_SERIALIZER
		Froot():head(){}
};

struct FIdolJson:public FJsonSerializable{
	FString alternateName;
	FString birthDate;
	FString birthPlace;
	FString description;
	FString familyName;
	FString gender;
	FString givenName;
	float height;
	TArray<FMemberOf> memberOf;
	FString name;
	TArray<FOwn> own;
	float weight;
	uint32 age;
	FString attribute;
	FString bloodType;
	float bust;
	FString category;
	FString color;
	FString constellation;
	FString division;
	TArray<FFavorite> favorite;
	FString handedness;
	float hip;
	TArray<FHobby> hobby;
	float shoeSize;
	TArray<FTalent> talent;
	FString title;
	float waist;
	FString alternateNameKana;
	FString cv;
	FString familyNameKana;
	FString givenNameKana;
	FString nameKana;

	BEGIN_JSON_SERIALIZER
		JSON_SERIALIZE("alternateName", alternateName);
	JSON_SERIALIZE("birthDate", birthDate);
	JSON_SERIALIZE("birthPlace", birthPlace);
	JSON_SERIALIZE("description", description);
	JSON_SERIALIZE("familyName", familyName);
	JSON_SERIALIZE("gender", gender);
	JSON_SERIALIZE("givenName", givenName);
	JSON_SERIALIZE("height", height);
	JSON_SERIALIZE_ARRAY_SERIALIZABLE("memberOf", memberOf, FMemberOf);
	JSON_SERIALIZE("name", name);
	JSON_SERIALIZE_ARRAY_SERIALIZABLE("own", own, FOwn);
	JSON_SERIALIZE("weight", weight);
	JSON_SERIALIZE("age", age);
	JSON_SERIALIZE("attribute", attribute);
	JSON_SERIALIZE("bloodType", bloodType);
	JSON_SERIALIZE("bust", bust);
	JSON_SERIALIZE("category", category);
	JSON_SERIALIZE("color", color);
	JSON_SERIALIZE("constellation", constellation);
	JSON_SERIALIZE("division", division);
	JSON_SERIALIZE_ARRAY_SERIALIZABLE("favorite", favorite, FFavorite);
	JSON_SERIALIZE("handedness", handedness);
	JSON_SERIALIZE("hip", hip);
	JSON_SERIALIZE_ARRAY_SERIALIZABLE("hobby", hobby, FHobby);
	JSON_SERIALIZE("shoeSize", shoeSize);
	JSON_SERIALIZE_ARRAY_SERIALIZABLE("talent", talent, FTalent);
	JSON_SERIALIZE("title", title);
	JSON_SERIALIZE("waist", waist);
	JSON_SERIALIZE("alternateNameKana", alternateNameKana);
	JSON_SERIALIZE("cv", cv);
	JSON_SERIALIZE("familyNameKana", familyNameKana);
	JSON_SERIALIZE("givenNameKana", givenNameKana);
	JSON_SERIALIZE("nameKana", nameKana);
	END_JSON_SERIALIZER

		FIdolJson():
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
		nameKana(""){}
};

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

	FIdol operator=(const FIdolJson& in){
		this->age = in.age;
		this->alternateName = in.alternateName;
		this->alternateNameKana = in.alternateNameKana;
		this->attribute = in.attribute;
		this->birthDate = in.birthDate;
		this->birthPlace = in.birthPlace;
		this->bloodType = in.bloodType;
		this->bust = in.bust;
		this->category = in.category;
		this->color = in.color;
		this->constellation = in.constellation;
		this->cv = in.cv;
		this->description = in.description;
		this->division = in.division;
		this->familyName = in.familyName;
		this->familyNameKana = in.familyNameKana;
		for(auto i : in.favorite){ this->favorite.Emplace(i.favorite); }
		this->gender = in.gender;
		this->givenName = in.givenName;
		this->givenNameKana = in.givenNameKana;
		this->handedness = in.handedness;
		this->height = in.height;
		this->hip = in.hip;
		for(auto i : in.hobby){ this->hobby.Emplace(i.hobby); }
		for(auto i : in.memberOf){ this->memberOf.Emplace(i.memberOf); }
		this->name = in.name;
		this->nameKana = in.nameKana;
		for(auto i : in.own){ this->own.Emplace(i.own); }
		this->shoeSize = in.shoeSize;
		for(auto i : in.talent){ this->talent.Emplace(i.talent); }
		this->title = in.title;
		this->waist = in.waist;
		this->weight = in.weight;

		return *this;
	}
};

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
	a(
		cereal::make_nvp("type", in.type),
		cereal::make_nvp("datatype", in.datatype),
		cereal::make_nvp("xml:lang", in.xml_lang),
		cereal::make_nvp("value", in.value)
	);
}
USTRUCT(BlueprintType)
struct FimasparqlBinding{
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FimasparqlResultUnit predicate;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FimasparqlResultUnit object;
};
template<typename T>
void serialize(T& a, FimasparqlBinding& in){
	a(
		cereal::make_nvp("predicate", in.predicate),
		cereal::make_nvp("object", in.object)
	);
}
USTRUCT(BlueprintType)
struct FimasparqlBindings{
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		TArray<FimasparqlBinding> binding;
};
template<typename T>
void serialize(T& a, FimasparqlBindings& in){
	a(
		cereal::make_nvp("binding", in.binding)
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
	a(cereal::make_nvp("vars", in.vars));
}
USTRUCT(BlueprintType)
struct FimasparqlResult{
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FimasparqlBindings bindings;
};
template<typename T>
void serialize(T& a, FimasparqlResult& in){
	a(cereal::make_nvp("bindings", in.bindings));
}