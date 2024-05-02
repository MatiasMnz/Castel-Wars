// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


class USoundBase;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
UPROPERTY(EditDefaultsOnly,Category = "Combat")
UStaticMeshComponent* ProjectileMesh;

UPROPERTY(VisibleAnywhere,Category = "Movement")
class UProjectileMovementComponent* ProjectileMovementComponent;

UPROPERTY(EditAnyWhere)
float Damage = 50.f;

UPROPERTY(EditAnyWhere, Category = "Combat")
class UParticleSystem* HitParticle;

UPROPERTY(VisibleAnyWhere, Category = "Combat")
class UParticleSystemComponent* TrailParticle;

UPROPERTY(EditAnyWhere, Category= "Combat")
USoundBase* LaunchSound;

UPROPERTY(EditAnyWhere, Category= "Combat")
USoundBase* HitSound;

UPROPERTY(EditAnyWhere, Category = "Combat")
TSubclassOf <class UCameraShakeBase> HitCameraShakeClass;

UFUNCTION()
void OnHit(UPrimitiveComponent* HitComp,AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
