// Fill out your copyright notice in the Description page of Project Settings.

#include "imasparqlBP.h"

FString UimasparqlBP::HelloWorld(){
	return "Hello im@sparql.";
}

FIdol UimasparqlBP::CreateIdol(){
	return FIdol();
}

FIdol UimasparqlBP::GetIdolData(FString name){
	FIdol ret;

	auto& http = FHttpModule::Get();
	auto& manager = http.GetHttpManager();
	TSharedRef<IHttpRequest> request = http.CreateRequest();
	request->OnProcessRequestComplete().BindUObject(this, &UimasparqlBP::OnComplete);
	request->SetURL("https://sparql.crssnky.xyz/spql/imas/query?force-accept=text%2Fplain&query=PREFIX%20schema%3A%20%3Chttp%3A%2F%2Fschema.org%2F%3E%0A%0Aselect%20distinct%20%3Fpredicate%20%3Fobject%0Awhere%7B%0A%20%20%3Fidol_iri%20%3Fpredicate%20%3Fobject%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20schema%3Aname%20%22%E5%A4%A9%E6%B5%B7%E6%98%A5%E9%A6%99%22%40ja%0A%7D");
	request->SetVerb("GET");
	request->SetHeader("User-Agent", "X-UnrealEngine-Agent");
	request->ProcessRequest();

	manager.AddRequest(request);
	return ret;
}

UimasparqlBP* UimasparqlBP::GetImasparqlBP(){
	return NewObject<UimasparqlBP>();
}

void UimasparqlBP::OnComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful){
	auto& http = FHttpModule::Get();
	auto& manager = http.GetHttpManager();

	if(!bWasSuccessful){
		UE_LOG(LogTemp, Warning, TEXT("No Response."));
	} else{
		auto txt = Response->GetContentAsString();

		FimasparqlHead json;
		FimasparqlResult json2;
		std::stringstream buf;
		buf << TCHAR_TO_UTF8(*txt);
		cereal::JSONInputArchive a(buf);
		a(json);
		a(json2);
		for(auto i : json.vars){
			UE_LOG(LogTemp, Warning, TEXT("var:%s"), *i);
		}
	}
	manager.RemoveRequest(Request.ToSharedRef());
}
