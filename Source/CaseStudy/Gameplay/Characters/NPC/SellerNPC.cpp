// Fill out your copyright notice in the Description page of Project Settings.


#include "SellerNPC.h"
#include "CaseStudy/Gameplay/UI/W_InteractionPopUp.h"
#include "CaseStudy/Gameplay/Characters/Player/Components/AC_Hotbar.h"
#include "CaseStudy/Gameplay/Characters/Player/CaseStudyCharacter.h"

void ASellerNPC::MakeInteraction(AActor* InteractingActor)
{
    if (InteractingActor->IsA(ACaseStudyCharacter::StaticClass())) 
    {
        PlayerActorRef = InteractingActor;
    }

	CreatePopUpWidget();
}

bool ASellerNPC::CreatePopUpWidget()
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

void ASellerNPC::PlayPopUpMontage()
{
    GetMesh()->GetAnimInstance()->Montage_Play(PopUpMontage);
}

void ASellerNPC::GiveHavedHotbarItemToPlayer()
{
    if (UAC_Hotbar* PlayerHotbarComp = Cast<UAC_Hotbar>(PlayerActorRef->GetComponentByClass(UAC_Hotbar::StaticClass())))
    {
        PlayerHotbarComp->AddHotbarItem(HotbarItemClass);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Hotbar component couldn't find in: %s"), *GetName());
    }
}
