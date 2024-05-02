// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	ATank();

		// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

void HandleDestruction();

APlayerController* GetTankPlayerController() const {return TankPlayerController;}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool bAlive = true;

private:

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "ComponentsTank", meta = (AllowPrivateAccess = "True"))
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "ComponentsTank", meta = (AllowPrivateAccess = "True"))
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 200.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 360.f;
	
	void Move(float Value);
	void Turn(float Value);

	APlayerController* TankPlayerController;
};
