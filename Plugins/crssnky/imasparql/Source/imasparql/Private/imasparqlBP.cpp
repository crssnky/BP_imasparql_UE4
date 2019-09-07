// Fill out your copyright notice in the Description page of Project Settings.

#include "imasparqlBP.h"

#include "cereal/archives/json.hpp"

void AimasparqlBP::GetIdolData(FString name) {
	auto& http = FHttpModule::Get();
	TSharedRef<IHttpRequest> request = http.CreateRequest();
	request->OnProcessRequestComplete().BindUObject(this, &AimasparqlBP::OnCompleteGetIdolData);
	request->SetURL("https://sparql.crssnky.xyz/spql/imas/query?\
force-accept=text%2Fplain&query=select%20distinct%20%3fpredicate\
%20%3fobject%0d%0awhere%7b%0d%0a%20%20%3fidol_iri%20%3fpredicate\
%20%3fobject%3b%0d%0a%20%20%3chttp%3a%2f%2fschema%2eorg%2fname\
%3e%20%22" + FGenericPlatformHttp::UrlEncode(name) + "%22%40ja%0A%7D");
	request->SetVerb("GET");
	request->SetHeader("User-Agent", "X-UnrealEngine-Agent");
	request->ProcessRequest();

	auto& manager = http.GetHttpManager();
	manager.AddRequest(request);
}

void AimasparqlBP::OnCompleteGetIdolData(FHttpRequestPtr req, FHttpResponsePtr res, bool bSuccess) {
	auto& http = FHttpModule::Get();
	auto& manager = http.GetHttpManager();

	if (!bSuccess) {
		UE_LOG(LogTemp, Warning, TEXT("No Response."));
	}
	else {
		auto txt = res->GetContentAsString();
		if (!txt.Left(1).Contains("{")) {
			UE_LOG(LogTemp, Warning, TEXT("ERROR in response. Query is wrong."));
			return;
		}

		FimasparqlHead head;
		FimasparqlResult result;
		std::stringstream buf;
		buf << TCHAR_TO_UTF8(*txt);
		cereal::JSONInputArchive a(buf);
		a(head, result);

		FIdol idol(result);
		OnGetIdolData(idol);
	}
	manager.RemoveRequest(req.ToSharedRef());
}
