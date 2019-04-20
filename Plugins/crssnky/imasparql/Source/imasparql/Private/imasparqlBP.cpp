// Fill out your copyright notice in the Description page of Project Settings.

#include "imasparqlBP.h"

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

	auto & manager = http.GetHttpManager();
	manager.AddRequest(request);
}

void AimasparqlBP::GetVoteData()
{
	auto& http = FHttpModule::Get();
	TSharedRef<IHttpRequest> request = http.CreateRequest();
	request->OnProcessRequestComplete().BindUObject(this, &AimasparqlBP::OnCompleteGetVoteData);
	request->SetURL("https://sparql.crssnky.xyz/spql/imas/query?force-accept=text%2Fplain&query=PREFIX%20schema%3a%20%3chttp%3a%2f%2fschema%2eorg%2f%3e%0d%0aPREFIX%20imas%3a%20%3chttps%3a%2f%2fsparql%2ecrssnky%2exyz%2fimasrdf%2fURIs%2fimas%2dschema%2ettl%23%3e%0d%0aSELECT%20%20%28SUM%28%3fa%29%20as%20%3fpredicate%29%20%28Sample%28%3fnm%29%20as%20%3fobject%29%20%28Sample%28%3fc%29%20as%20%3fColor%29%0d%0aWHERE%20%7b%0d%0a%20%20%3fs%20schema%3amember%20%3fo%3b%0d%0a%20%20%20%20%20imas%3aVoteNumber%20%3fa%2e%0d%0a%20%20%3fo%20schema%3aname%20%3fnm%3b%0d%0a%20%20%20%20%20imas%3aColor%20%3fc%2e%0d%0a%7dgroup%20by%28%3fo%29%20order%20by%28%3fpredicate%29");
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

void AimasparqlBP::OnCompleteGetVoteData(FHttpRequestPtr req, FHttpResponsePtr res, bool bSuccess)
{
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

		TArray<FVote> data;
		FVote::makeVoteData(result, &data);
		OnGetVoteData(data);
	}
	manager.RemoveRequest(req.ToSharedRef());
}
