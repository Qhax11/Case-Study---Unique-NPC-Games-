// Fill out your copyright notice in the Description page of Project Settings.


#include "W_HotbarPanel.h"
#include "Blueprint/WidgetTree.h"
#include "CaseStudy/Gameplay/UI/W_Hotbar.h"
#include "CaseStudy/Gameplay/Actors/A_HotbarItem.h"


void UW_HotbarPanel::NativeConstruct()
{
    Super::NativeConstruct();

    TArray<UWidget*> Widgets;
    WidgetTree->GetAllWidgets(Widgets);
    for (UWidget* Widget : Widgets)
    {
        UW_Hotbar* FoundHotbarWidget = Cast<UW_Hotbar>(Widget);
        if (FoundHotbarWidget)
        {
            HotbarWidgets.Add(FoundHotbarWidget);
        }
    }

    int32 Num = 1;
    for (int32 i = 0; i < HotbarWidgets.Num(); i++)
    {
        HotbarWidgets[i]->SetInputNum(Num);
        Num++;
    }
}

bool UW_HotbarPanel::AddHotbarToEmptySlot(AA_HotbarItem* HotbarItem)
{
    for (UW_Hotbar* HotbarWidget : HotbarWidgets)
    {
        if (!HotbarWidget->bIsValid)
        {
            HotbarWidget->AddHotbarData(HotbarItem->ItemData);
            return true;
        }
    }

    return false;
}
