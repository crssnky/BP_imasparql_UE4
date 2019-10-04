// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Http.h"
#include "HttpManager.h"

#include "imasparqlJsonStructs.h"

#include "imasparqlBP.generated.h"

/**
 *
 */
UCLASS(Blueprintable, BlueprintType)
class AimasparqlBP: public AActor{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "imasparql")
		void GetIdolData(FString name);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "imasparql")
		void OnGetIdolData(const FIdol& idol);

private:
	void OnCompleteGetIdolData(FHttpRequestPtr req, FHttpResponsePtr res, bool bSuccess);
};
