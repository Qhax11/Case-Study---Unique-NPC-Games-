// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_Hotbar.h"
#include "CaseStudy/Gameplay/UI/W_Hotbar.h"
#include "EnhancedInputComponent.h"
#include "CaseStudy/Gameplay/Actors/A_HotbarItem.h"

UAC_Hotbar::UAC_Hotbar()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_Hotbar::BeginPlay()
{
	Super::BeginPlay();

    if (!TryCreateWidget()) 
    {
        UE_LOG(LogTemp, Warning, TEXT("Widget creating is failed in: %s"), *GetName());
    }
}

bool UAC_Hotbar::TryCreateWidget()
{
    if (HotbarWidgetClass)
    {
        UW_Hotbar* HotbarWidget = Cast<UW_Hotbar>(CreateWidget<UW_Hotbar>(GetWorld()->GetFirstPlayerController(), HotbarWidgetClass));
        if (HotbarWidget)
        {
            HotbarWidget->AddToViewport();
            return true;
        }
    }

    return false;
}

bool UAC_Hotbar::TryBindInputs()
{
    if (UEnhancedInputComponent* OwnerEnhancedInputComp = Cast<UEnhancedInputComponent>(GetOwner()->InputComponent))
    {
        OwnerEnhancedInputComp->BindAction(IA_HotbarNum1, ETriggerEvent::Triggered, this, &UAC_Hotbar::OnHotbarNum1);
        OwnerEnhancedInputComp->BindAction(IA_HotbarNum2, ETriggerEvent::Triggered, this, &UAC_Hotbar::OnHotbarNum2);
        OwnerEnhancedInputComp->BindAction(IA_HotbarNum3, ETriggerEvent::Triggered, this, &UAC_Hotbar::OnHotbarNum3);
        return true;
    }

    return false;
}

void UAC_Hotbar::OnHotbarNum1()
{
    TryToUseHotbarItem(1);
}

void UAC_Hotbar::OnHotbarNum2()
{
    TryToUseHotbarItem(2);
}

void UAC_Hotbar::OnHotbarNum3()
{
    TryToUseHotbarItem(3);
}

void UAC_Hotbar::TryToUseHotbarItem(int32 Index)
{
    if (Items.IsValidIndex(Index)) 
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (TEXT("Used: %s"), *Items[Index]->GetName()));
    }
}

bool UAC_Hotbar::AddItemToHotbar(AA_HotbarItem* HotbarItem)
{
    if (!HotbarItem) 
    {
        return false;
    }

    Items.Add(HotbarItem);
    return true;
}



