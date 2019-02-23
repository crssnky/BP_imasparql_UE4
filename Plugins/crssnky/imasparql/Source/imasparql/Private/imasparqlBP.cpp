// Fill out your copyright notice in the Description page of Project Settings.

#include "imasparqlBP.h"

FString AimasparqlBP::HelloWorld(){
	return "Hello im@sparql.";
}

FIdol AimasparqlBP::CreateIdol(){
	return FIdol();
}

FIdol AimasparqlBP::GetIdolData(FString name){
	FIdol ret;

	auto& http = FHttpModule::Get();
	auto& manager = http.GetHttpManager();
	TSharedRef<IHttpRequest> request = http.CreateRequest();
	request->OnProcessRequestComplete().BindUObject(this, &AimasparqlBP::OnCompleteGetIdolData);
	request->SetURL("https://sparql.crssnky.xyz/spql/imas/query?force-accept=text%2Fplain&query=PREFIX%20schema%3A%20%3Chttp%3A%2F%2Fschema.org%2F%3E%0A%0Aselect%20distinct%20%3Fpredicate%20%3Fobject%0Awhere%7B%0A%20%20%3Fidol_iri%20%3Fpredicate%20%3Fobject%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20schema%3Aname%20%22" + name + "%22%40ja%0A%7D");
	request->SetVerb("GET");
	request->SetHeader("User-Agent", "X-UnrealEngine-Agent");
	request->ProcessRequest();

	manager.AddRequest(request);
	return ret;
}

AimasparqlBP* AimasparqlBP::GetImasparqlBP(){
	return NewObject<AimasparqlBP>();
}

void AimasparqlBP::OnCompleteGetIdolData(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful){
	auto& http = FHttpModule::Get();
	auto& manager = http.GetHttpManager();

	if(!bWasSuccessful){
		UE_LOG(LogTemp, Warning, TEXT("No Response."));
	} else{
		auto txt = Response->GetContentAsString();

		FimasparqlHead head;
		FimasparqlResult result;
		std::stringstream buf;
		buf << TCHAR_TO_UTF8(*txt);
		cereal::JSONInputArchive a(buf);
		a(head, result);

		FIdol idol;
		for(auto building : result.bindings){
			auto& object = building.object.value;
			auto& predicate = building.predicate.value;

			if(predicate == "http://schema.org/alternateName"){
				idol.alternateName = object;
			} else if(predicate == "http://schema.org/birthDate"){
				idol.birthDate = object;
			} else if(predicate == "http://schema.org/birthPlace"){
				idol.birthPlace = object;
			} else if(predicate == "http://schema.org/description"){
				idol.description = object;
			} else if(predicate == "http://schema.org/familyName"){
				idol.familyName = object;
			} else if(predicate == "http://schema.org/gender"){
				idol.gender = object;
			} else if(predicate == "http://schema.org/givenName"){
				idol.givenName = object;
			} else if(predicate == "http://schema.org/height"){
				idol.height = FCString::Atof(*object);
			} else if(predicate == "http://schema.org/memberOf"){
				idol.memberOf.Emplace(object);
			} else if(predicate == "http://schema.org/name"){
				idol.name = object;
			} else if(predicate == "http://schema.org/owns"){
				idol.own.Emplace(object);
			} else if(predicate == "http://schema.org/weight"){
				idol.weight = FCString::Atof(*object);
			} else if(predicate == "http://xmlns.com/foaf/0.1/age"){
				idol.age = FCString::Atoi(*object);
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Attribute"){
				idol.attribute = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#bloodType"){
				idol.bloodType = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Bust"){
				idol.bust = FCString::Atof(*object);
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Category"){
				idol.category = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Color"){
				idol.color = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Constellation"){
				idol.constellation = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Division"){
				idol.division = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Favorite"){
				idol.favorite.Emplace(object);
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Handedness"){
				idol.handedness = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Hip"){
				idol.hip = FCString::Atof(*object);
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Hobby"){
				idol.hobby.Emplace(object);
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#ShoeSize"){
				idol.shoeSize = FCString::Atof(*object);
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Talent"){
				idol.talent.Emplace(object);
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Title"){
				idol.title = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Waist"){
				idol.waist = FCString::Atof(*object);
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#alternateNameKana"){
				idol.alternateNameKana = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#cv"){
				idol.cv = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#familyNameKana"){
				idol.familyNameKana = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#givenNameKana"){
				idol.givenNameKana = object;
			} else if(predicate == "https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#nameKana"){
				idol.nameKana = object;
			} else if(predicate != "http://www.w3.org/1999/02/22-rdf-syntax-ns#type"){
				UE_LOG(LogTemp, Warning, TEXT("unknown predicate : %s"), *predicate);
			}
		}
		OnGetIdolData(idol);
	}
	manager.RemoveRequest(Request.ToSharedRef());
}
