// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "W_Hotbar.generated.h"

class UTextBlock;

UCLASS()
class CASESTUDY_API UW_Hotbar : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> T_HotbarItemName;
};
