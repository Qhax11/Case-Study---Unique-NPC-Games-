// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCBase.h"
#include "CaseStudy/Gameplay/UI/W_InteractionPopUp.h"
#include "CaseStudy/Gameplay/Characters/Player/Components/AC_Hotbar.h"

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
    Player = InteractingActor;
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

void ANPCBase::PlayPopUpMontage()
{
    GetMesh()->GetAnimInstance()->Montage_Play(PopUpMontage);
}

void ANPCBase::GiveHavedHotbarItemToPlayer()
{
    if (UAC_Hotbar* PlayerHotbarComp = Cast<UAC_Hotbar>(Player->GetComponentByClass(UAC_Hotbar::StaticClass())))
    {
        PlayerHotbarComp->AddHotbarItem(HotbarItemClass);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Hotbar component couldn't find in: %s"), *GetName());
    }
}


