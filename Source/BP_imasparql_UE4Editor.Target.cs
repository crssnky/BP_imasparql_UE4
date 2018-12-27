// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BP_imasparql_UE4EditorTarget : TargetRules
{
	public BP_imasparql_UE4EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "BP_imasparql_UE4" } );
	}
}
