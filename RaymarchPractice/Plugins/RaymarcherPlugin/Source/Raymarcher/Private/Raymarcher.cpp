// Copyright Epic Games, Inc. All Rights Reserved.

#include "Raymarcher.h"

#define LOCTEXT_NAMESPACE "FRaymarcherModule"

void FRaymarcherModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FString ShaderDir = FPaths::Combine(
		FPaths::ProjectPluginsDir(), TEXT("RaymarcherPlugin/Source/Raymarcher/Shaders"));
	AddShaderSourceDirectoryMapping("/Raymarcher", ShaderDir);
}

void FRaymarcherModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRaymarcherModule, Raymarcher)