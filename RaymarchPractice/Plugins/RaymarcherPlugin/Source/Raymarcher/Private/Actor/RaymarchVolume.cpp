// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/RaymarchVolume.h"

// Sets default values
ARaymarchVolume::ARaymarchVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent->SetWorldScale3D(FVector(1.0f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> UnitCubeInsideOut(
		TEXT("/RaymarcherPlugin/Meshes/Unit_Cube_Inside_Out.Unit_Cube_Inside_Out"));	

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Raymarch Cube Static Mesh"));
	if(UnitCubeInsideOut.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(UnitCubeInsideOut.Object);
		StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
		StaticMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		StaticMeshComponent->SetRelativeScale3D(FVector(100.0f));
		StaticMeshComponent->SetupAttachment(RootComponent);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> IntensityMaterial(
		TEXT("/RaymarcherPlugin/Materials/M_Intensity_Raymarch.M_Intensity_Raymarch"));

	if(IntensityMaterial.Succeeded())
	{
		IntensityRaymarchMaterialBase = IntensityMaterial.Object;
	}

    if(IntensityRaymarchMaterialBase)
    {
        StaticMeshComponent->SetMaterial(0, IntensityRaymarchMaterialBase);	
	}

}

// Called when the game starts or when spawned
void ARaymarchVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARaymarchVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

