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

void ANPCBase::MakeInteraction()
{
    if (InteractionPopUpClass)
    {
        UW_InteractionPopUp* InteractionPopUpWidget = Cast<UW_InteractionPopUp>(CreateWidget<UW_InteractionPopUp>(GetWorld()->GetFirstPlayerController(), InteractionPopUpClass));
        if (InteractionPopUpWidget)
        {
            InteractionPopUpWidget->AddToViewport();
        }
    }
}



