﻿// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "imasparql.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
//#include "JsonStructs.h"


class Fimasparql: public Iimasparql
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(Fimasparql, imasparql)



void Fimasparql::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void Fimasparql::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}



