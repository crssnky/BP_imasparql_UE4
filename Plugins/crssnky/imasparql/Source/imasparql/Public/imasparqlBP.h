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
class IMASPARQL_API AimasparqlBP: public AActor{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "imasparql")
		static FString HelloWorld();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "imasparql")
		static FIdol CreateIdol();

	UFUNCTION(BlueprintCallable, Category = "imasparql")
		FIdol GetIdolData(FString name);

	UFUNCTION(BlueprintCallable, Category = "imasparql")
		static AimasparqlBP* GetImasparqlBP();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "imasparql")
		void OnGetIdolData(const FIdol& idol);

private:
	void OnCompleteGetIdolData(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
