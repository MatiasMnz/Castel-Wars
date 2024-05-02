// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksPlayerController.h"
#include "GameFramework/Pawn.h"

void AToonTanksPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        if (bPlayerEnabled)
        {
            ControlledPawn->EnableInput(this);
        }
        else
        {
            ControlledPawn->DisableInput(this);
        }
    }

    bShowMouseCursor = bPlayerEnabled;
}

