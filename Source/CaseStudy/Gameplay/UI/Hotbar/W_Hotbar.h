// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "W_Hotbar.generated.h"

struct FHotbarItemData;

UCLASS()
class CASESTUDY_API UW_Hotbar : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> T_HotbarItemName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UImage> IMG_HotbarItemImage;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> T_InputNum;

	void AddHotbarData(FHotbarItemData& HotbarItemData);

	void SetInputNum(int32 InputNum);

	bool bIsValid = false;
};
