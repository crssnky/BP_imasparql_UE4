// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules {
	public class imasparql : ModuleRules {
		public imasparql(ReadOnlyTargetRules Target) : base(Target) {
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
			bUseRTTI = true;

			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					// ... add other public dependencies that you statically link with here ...
					"Json",
					"Http",
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);

			// cereal
			var base_path = Path.GetDirectoryName(RulesCompiler.GetFileNameFromType(GetType()));
			string third_party_path = Path.Combine(base_path, "..", "..", "Thirdparty");
			PublicIncludePaths.Add(Path.Combine(third_party_path, "cereal", "include"));
			PublicIncludePaths.Add(Path.Combine(third_party_path, "cereal-UE4", "include"));

		}
	}
}
