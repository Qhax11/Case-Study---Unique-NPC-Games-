// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCBase.h"
#include "CaseStudy/Gameplay/UI/W_InteractionPopUp.h"

ANPCBase::ANPCBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ANPCBase::BeginPlay()
{
	Super::BeginPlay();
}

void ANPCBase::MakeInteraction(AActor* InteractingActor)
{
    CreatePopUpWidget();
}

bool ANPCBase::CreatePopUpWidget()
{
    if (!InteractionPopUpClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("InteractionPopUpClass is null in: %s"), *GetName());
        return false;
    }

    if (UW_InteractionPopUp* InteractionPopUpWidget = Cast<UW_InteractionPopUp>(CreateWidget<UW_InteractionPopUp>(GetWorld()->GetFirstPlayerController(), InteractionPopUpClass)))
    {
        InteractionPopUpWidget->CustomInitialize(this);
        InteractionPopUpWidget->AddToViewport();
        return true;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("InteractionPopUpWidget is null in: %s"), *GetName());
        return false;
    }
}



