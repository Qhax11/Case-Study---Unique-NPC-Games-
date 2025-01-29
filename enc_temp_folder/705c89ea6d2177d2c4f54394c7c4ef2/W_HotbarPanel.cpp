// Fill out your copyright notice in the Description page of Project Settings.


#include "W_HotbarPanel.h"
#include "Blueprint/WidgetTree.h"

void UW_HotbarPanel::NativeConstruct()
{
    Super::NativeConstruct();

    UUserWidget* FoundWidget = nullptr;
    TArray<UWidget*> Widgets;
    WidgetTree->GetAllWidgets(Widgets);
    for (UWidget* Widget : Widgets)
    {
        FoundWidget = Cast<UUserWidget>(Widget);
        if (FoundWidget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Found a child widget: %s"), *FoundWidget->GetName());
        }
    }
}
