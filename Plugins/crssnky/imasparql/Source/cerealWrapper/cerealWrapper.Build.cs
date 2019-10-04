// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class cerealWrapper : ModuleRules
	{
		public cerealWrapper(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.NoSharedPCHs;
			PrivatePCHHeaderFile = "Public/cerealWrapper.h";
			bUseRTTI = true;

			PublicDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject"
				});

			// cereal
			var base_path = Path.GetDirectoryName(RulesCompiler.GetFileNameFromType(GetType()));
			string third_party_path = Path.Combine(base_path, "..", "..", "Thirdparty");
			PrivateIncludePaths.Add(Path.Combine(third_party_path, "cereal", "include"));
			PrivateIncludePaths.Add(Path.Combine(third_party_path, "cereal-UE4", "include"));
		}
	}
}
