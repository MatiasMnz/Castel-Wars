// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

void HandleDestruction();

protected:
void RotateTurret (FVector LookAtTarget);
void Fire();
FTimerHandle ShootTimerHandle;

private:
UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta= (AllowPrivateAccess = "true"));
class UCapsuleComponent* CapsuleComp;

UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta= (AllowPrivateAccess = "true"));
UStaticMeshComponent* BaseMesh;

UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta= (AllowPrivateAccess = "true"));
UStaticMeshComponent* TurretMesh;

UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta= (AllowPrivateAccess = "true"));
USceneComponent* ProjectileSpawnPoint;

UPROPERTY(EditDefaultsOnly, Category = "Combat")
TSubclassOf<class AProjectile> ProjectileClass;

UPROPERTY(EditAnywhere, Category = "Combat")
class UParticleSystem* DestroyParticle;

UPROPERTY(EditAnywhere, Category = "Combat")
class USoundBase* DeathSound;

UPROPERTY(EditAnywhere, Category = "Combat")
TSubclassOf <class UCameraShakeBase> DeathCameraShakeClass;
//UPROPERTY(VisibleAnyWhere, BluePrintReadOnly, Category = "Variables", meta= (AllowPrivateAccess = "true"))
//int32 VisibleAnywhereInt = 32;

//UPROPERTY(EditAnyWhere, BluePrintReadWrite,Category = "Variables", meta= (AllowPrivateAccess = "true"))
//float Speed = 400.f;

};
