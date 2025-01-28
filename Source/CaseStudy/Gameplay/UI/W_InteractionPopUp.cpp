// Fill out your copyright notice in the Description page of Project Settings.


#include "W_InteractionPopUp.h"
#include "Components/Button.h"

void UW_InteractionPopUp::NativeConstruct()
{
    Super::NativeConstruct();

    if (PlayAnimationButton && PlaySoundButton)
    {
        PlayAnimationButton->OnClicked.AddDynamic(this, &UW_InteractionPopUp::OnPlayAnimationButtonClicked);
        PlaySoundButton->OnClicked.AddDynamic(this, &UW_InteractionPopUp::OnPlaySoundButtonClicked);
    }
   
}

void UW_InteractionPopUp::OnPlayAnimationButtonClicked()
{
}

void UW_InteractionPopUp::OnPlaySoundButtonClicked()
{
}
