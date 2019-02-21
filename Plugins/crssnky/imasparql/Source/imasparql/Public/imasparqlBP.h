// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Http.h"
#include "HttpManager.h"

#include "imasparqlJsonStructs.h"

#include "imasparqlBP.generated.h"
/**
 *
 */
UCLASS(Blueprintable, BlueprintType)
class IMASPARQL_API UimasparqlBP: public UBlueprintFunctionLibrary{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "imasparql")
		static FString HelloWorld();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "imasparql")
		static FIdol CreateIdol();

	//UFUNCTION(BlueprintCallable, BlueprintPure, Category = "imasparql")
	//	static FIdol GetIdolData(FString name);

	UFUNCTION(BlueprintCallable, Category = "imasparql")
		FIdol GetIdolData(FString name);

	UFUNCTION(BlueprintCallable, Category = "imasparql")
		static UimasparqlBP* GetImasparqlBP();

	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "imasparql")
	//	void OnRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

private:
	void OnComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
