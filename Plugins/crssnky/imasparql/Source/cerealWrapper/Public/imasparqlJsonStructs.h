#pragma once

#include "CoreMinimal.h"
#include "cerealWrapper.h"

#include "imasparqlJsonStructs.generated.h"

template<class A, class T>
static void OptionalField(A& a, const std::string& name, T& t) {
	try {
		a(make_nvp(name, t));
	}
	catch (std::exception& e) {
		(void)e;
	}
}
USTRUCT(BlueprintType)
struct FimasparqlResultUnit {
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
void serialize(T& a, FimasparqlResultUnit& in) {
	OptionalField(a, "datatype", in.datatype);
	OptionalField(a, "xml:lang", in.xml_lang);
	a(
		make_nvp("type", in.type),
		//make_nvp("datatype", in.datatype),
		//make_nvp("xml:lang", in.xml_lang),
		make_nvp("value", in.value)
	);
}
USTRUCT(BlueprintType)
struct FimasparqlBindings {
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FimasparqlResultUnit predicate;
	UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		FimasparqlResultUnit object;
};
template<typename T>
void serialize(T& a, FimasparqlBindings& in) {
	a(
		make_nvp("predicate", in.predicate),
		make_nvp("object", in.object)
	);
}
USTRUCT(BlueprintType)
struct FimasparqlResult {
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		TArray<FimasparqlBindings> bindings;
};
template<typename T>
void serialize(T& a, FimasparqlResult& in) {
	a(
		make_nvp("bindings", in.bindings)
	);
}
USTRUCT(BlueprintType)
struct FimasparqlHead {
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "imasparql")
		TArray<FString> vars;
};
template<typename T>
void serialize(T& a, FimasparqlHead& in) {
	a(
		make_nvp("vars", in.vars)
	);
}


USTRUCT(BlueprintType)
struct FIdol {
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
		FLinearColor color2;
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

	FIdol() :
		alternateName(""),
		birthDate(""),
		birthPlace(""),
		description(""),
		familyName(""),
		gender(""),
		givenName(""),
		height(0.0f),
		memberOf(),
		name(""),
		own(),
		weight(0.0f),
		age(0),
		attribute(""),
		bloodType(""),
		bust(0.0f),
		category(""),
		color(""),
		constellation(""),
		division(""),
		favorite(),
		handedness(""),
		hip(0.0f),
		hobby(),
		shoeSize(0.0f),
		talent(),
		title(""),
		waist(0.0f),
		alternateNameKana(""),
		cv(""),
		familyNameKana(""),
		givenNameKana(""),
		nameKana("") {}
	FIdol(const FimasparqlResult& in) :
		alternateName(""),
		birthDate(""),
		birthPlace(""),
		description(""),
		familyName(""),
		gender(""),
		givenName(""),
		height(0.0f),
		memberOf(),
		name(""),
		own(),
		weight(0.0f),
		age(0),
		attribute(""),
		bloodType(""),
		bust(0.0f),
		category(""),
		color(""),
		constellation(""),
		division(""),
		favorite(),
		handedness(""),
		hip(0.0f),
		hobby(),
		shoeSize(0.0f),
		talent(),
		title(""),
		waist(0.0f),
		alternateNameKana(""),
		cv(""),
		familyNameKana(""),
		givenNameKana(""),
		nameKana("") {
		(*this) = in;
	}

	FIdol operator=(const FimasparqlResult& in) {
		auto& out = *this;

		// check IsIdol
		const FimasparqlBindings* type = in.bindings.FindByPredicate([](const FimasparqlBindings& i) {
			return i.predicate.value == "http://www.w3.org/1999/02/22-rdf-syntax-ns#type";
			});
		if (nullptr == type) {
			UE_LOG(LogTemp, Warning, TEXT("It's not Idol info."));
			return out;
		}
		else if (type->object.value != "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Idol") {
			UE_LOG(LogTemp, Warning, TEXT("It's not Idol info."));
			return out;
		}

		// Get info
		for (auto building : in.bindings) {
			auto& object = building.object.value;
			auto& predicate = building.predicate.value;

			if (predicate == "http://schema.org/alternateName") {
				out.alternateName = object;
			}
			else if (predicate == "http://schema.org/birthDate") {
				out.birthDate = object;
			}
			else if (predicate == "http://schema.org/birthPlace") {
				out.birthPlace = object;
			}
			else if (predicate == "http://schema.org/description") {
				out.description = object;
			}
			else if (predicate == "http://schema.org/familyName") {
				out.familyName = object;
			}
			else if (predicate == "http://schema.org/gender") {
				out.gender = object;
			}
			else if (predicate == "http://schema.org/givenName") {
				out.givenName = object;
			}
			else if (predicate == "http://schema.org/height") {
				out.height = FCString::Atof(*object);
			}
			else if (predicate == "http://schema.org/memberOf") {
				out.memberOf.Emplace(object);
			}
			else if (predicate == "http://schema.org/name") {
				out.name = object;
			}
			else if (predicate == "http://schema.org/owns") {
				out.own.Emplace(object);
			}
			else if (predicate == "http://schema.org/weight") {
				out.weight = FCString::Atof(*object);
			}
			else if (predicate == "http://xmlns.com/foaf/0.1/age") {
				out.age = FCString::Atoi(*object);
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Attribute") {
				out.attribute = object;
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#bloodType") {
				out.bloodType = object;
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Bust") {
				out.bust = FCString::Atof(*object);
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Category") {
				out.category = object;
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Color") {
				out.color = object;
				out.color2 = FColor::FromHex(out.color);
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Constellation") {
				out.constellation = object;
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Division") {
				out.division = object;
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Favorite") {
				out.favorite.Emplace(object);
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Handedness") {
				out.handedness = object;
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Hip") {
				out.hip = FCString::Atof(*object);
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Hobby") {
				out.hobby.Emplace(object);
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#ShoeSize") {
				out.shoeSize = FCString::Atof(*object);
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Talent") {
				out.talent.Emplace(object);
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Title") {
				out.title = object;
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Waist") {
				out.waist = FCString::Atof(*object);
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#alternateNameKana") {
				out.alternateNameKana = object;
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#cv") {
				out.cv = object;
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#familyNameKana") {
				out.familyNameKana = object;
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#givenNameKana") {
				out.givenNameKana = object;
			}
			else if (predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#nameKana") {
				out.nameKana = object;
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("unknown predicate : %s"), *predicate);
			}
		}

		return out;
	}
};

