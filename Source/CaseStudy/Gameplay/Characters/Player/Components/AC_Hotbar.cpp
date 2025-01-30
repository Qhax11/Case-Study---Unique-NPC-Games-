// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_Hotbar.h"
#include "CaseStudy/Gameplay/UI/Hotbar/W_HotbarPanel.h"
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

    if (!TryBindInputs()) 
    {
        UE_LOG(LogTemp, Warning, TEXT("Binding is failed in: %s"), *GetName());
    }
}

bool UAC_Hotbar::TryCreateWidget()
{
    if (HotbarPanelWidgetClass)
    {
        HotbarPanelWidget = Cast<UW_HotbarPanel>(CreateWidget<UW_HotbarPanel>(GetWorld()->GetFirstPlayerController(), HotbarPanelWidgetClass));
        if (HotbarPanelWidget)
        {
            HotbarPanelWidget->AddToViewport();
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
    TryToUseHotbarItem(0);
}

void UAC_Hotbar::OnHotbarNum2()
{
    TryToUseHotbarItem(1);
}

void UAC_Hotbar::OnHotbarNum3() 
{
    TryToUseHotbarItem(2);
}

void UAC_Hotbar::TryToUseHotbarItem(int32 Index)
{
    if (Items.IsValidIndex(Index)) 
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (TEXT("Used: %s"), *Items[Index]->ItemData.Name.ToString()));
    }
    else 
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Item index is null!"));
    }
}

bool UAC_Hotbar::AddHotbarItem(AA_HotbarItem* HotbarItem)
{
    if (!HotbarItem) 
    {
        return false;
    }

    Items.Add(HotbarItem);
    if (HotbarPanelWidget->AddHotbarToEmptySlot(HotbarItem)) 
    {
        return true;
    }

    return false;
}

bool UAC_Hotbar::AddHotbarItem(TSubclassOf<AA_HotbarItem> HotbarItemClass)
{
    if (!HotbarItemClass)
    {
        return false;
    }

    AA_HotbarItem* HotBarItemCDO = Cast<AA_HotbarItem>(HotbarItemClass->GetDefaultObject());

    return AddHotbarItem(HotBarItemCDO);
}



