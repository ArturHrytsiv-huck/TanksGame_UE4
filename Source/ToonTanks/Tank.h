// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Basepawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasepawn
{
	GENERATED_BODY()

public:
	ATank();

	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void HandleDestruction();
	APlayerController* GetTankPlayerController() const
	{
		return TankPlayerController;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		USpringArmComponent* ArmComponent;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UCameraComponent* CameraComponent;


	void Move(float Value);
	void Turn(float Value);

	UPROPERTY(EditAnywhere)
		float Speed = 200.f;
	UPROPERTY(EditAnywhere)
		float RotationSpeed = 200.f;

	APlayerController* TankPlayerController;

};
