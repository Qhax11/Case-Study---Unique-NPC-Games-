// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "W_HotbarPanel.generated.h"

class UW_Hotbar;
class AA_HotbarItem;

UCLASS()
class CASESTUDY_API UW_HotbarPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct();

	bool AddHotbarToEmptySlot(AA_HotbarItem* HotbarItem);

	TArray<UW_Hotbar*> HotbarWidgets;
};
