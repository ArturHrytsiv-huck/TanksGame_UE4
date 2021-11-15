// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Basepawn.generated.h"

UCLASS()
class TOONTANKS_API ABasepawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasepawn();
	// Called every frame
	void HandleDestruction();

protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();

private:
	UPROPERTY(EditDefaultsOnly)
		class UCapsuleComponent* CapsuleComp; 
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* BaseMesh;
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* TurretMesh;
	UPROPERTY(EditDefaultsOnly)
		USceneComponent* ProjectileSpawnPoint;
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
		TSubclassOf<class AProjectile> ProjectileClass;
	
	UPROPERTY(EditAnywhere, Category = "Combat")
		class UParticleSystem* DeathParticles;
	UPROPERTY(EditAnyWhere, Category = "Combat")
		class USoundBase* DeathSound;
	UPROPERTY(EditAnywhere, Category = "Combat")
		TSubclassOf<class UCameraShake> DeathCameraShakeClass;
};
 