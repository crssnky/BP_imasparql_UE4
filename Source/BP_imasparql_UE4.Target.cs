// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BP_imasparql_UE4Target : TargetRules
{
	public BP_imasparql_UE4Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "BP_imasparql_UE4" } );
	}
}
