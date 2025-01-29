// Fill out your copyright notice in the Description page of Project Settings.


#include "W_InteractionPopUp.h"
#include "Components/Button.h"
#include "CaseStudy/Gameplay/Characters/NPC/NPCBase.h"

void UW_InteractionPopUp::NativeConstruct()
{
    Super::NativeConstruct();

    if (B_PlayAnimationButton && B_SayHiButton && B_TakeItemButton)
    {
        B_PlayAnimationButton->OnClicked.AddDynamic(this, &UW_InteractionPopUp::OnPlayAnimationButtonClicked);
        B_SayHiButton->OnClicked.AddDynamic(this, &UW_InteractionPopUp::OnSayHiButtonClicked);
        B_TakeItemButton->OnClicked.AddDynamic(this, &UW_InteractionPopUp::OnTakeItemButtonClicked);
    }
}

void UW_InteractionPopUp::CustomInitialize(ACharacter* OwnerChar)
{
    OwnerNPC = Cast<ANPCBase>(OwnerChar);
}

void UW_InteractionPopUp::OnPlayAnimationButtonClicked()
{
    if (OwnerNPC) 
    {
        OwnerNPC->PlayPopUpMontage();
    }
}

void UW_InteractionPopUp::OnSayHiButtonClicked()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hi!"));
}

void UW_InteractionPopUp::OnTakeItemButtonClicked()
{
    if (OwnerNPC)
    {
        OwnerNPC->GiveHavedHotbarItemToPlayer();
    }
}
