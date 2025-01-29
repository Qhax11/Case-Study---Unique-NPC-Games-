// Fill out your copyright notice in the Description page of Project Settings.


#include "W_InteractionPopUp.h"
#include "Components/Button.h"
#include "GameFramework/Character.h"

void UW_InteractionPopUp::NativeConstruct()
{
    Super::NativeConstruct();

    if (PlayAnimationButton && SayHiButton)
    {
        PlayAnimationButton->OnClicked.AddDynamic(this, &UW_InteractionPopUp::OnPlayAnimationButtonClicked);
        SayHiButton->OnClicked.AddDynamic(this, &UW_InteractionPopUp::OnSayHiButtonClicked);
    }
}

void UW_InteractionPopUp::CustomInitialize(ACharacter* OwnerChar)
{
    OwnerCharacter = OwnerChar;
}

void UW_InteractionPopUp::OnPlayAnimationButtonClicked()
{
    OwnerCharacter->GetMesh()->GetAnimInstance()->Montage_Play(Montage);
}

void UW_InteractionPopUp::OnSayHiButtonClicked()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hi!"));
}
