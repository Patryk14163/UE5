// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class PIERWSZY_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	// This variable is tagged as a UPROPERTY so that it will be visible 
	// to Unreal Engine. This is important because it prevents the variable 
	// from being reset when the game is launched, or when the project or level is closed and reloaded.
	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
