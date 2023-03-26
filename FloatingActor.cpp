// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh1"));
	VisualMesh1->SetupAttachment(RootComponent);

	VisualMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh2"));
	VisualMesh2->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>CubeVisualAsset1(TEXT("/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>CubeVisualAsset2(TEXT("/Game/StarterContent/Props/SM_Chair.SM_Chair"));

	// Coœ nie dzia³a, musi byæ tylko chyba jeden mesh, robiæ dalej z instrukcji

	if (CubeVisualAsset1.Succeeded())
	{
		VisualMesh1->SetStaticMesh(CubeVisualAsset1.Object);
		VisualMesh1->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));
	}

	if (CubeVisualAsset2.Succeeded())
	{
		VisualMesh2->SetStaticMesh(CubeVisualAsset2.Object);
		VisualMesh2->SetRelativeLocation(FVector(-50.0f, 0.0f, 0.0f));
	}

}					

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * FloatSpeed;			// Scale our height by a factor of 20
	float DeltaRotation = DeltaTime * RotationSpeed;		// Rotate by 20 degrees per second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);
}

