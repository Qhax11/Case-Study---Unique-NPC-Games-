// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AC_Hotbar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHotbarItemAdded, const AA_HotbarItem*, NewHotbarItem);

class AA_HotbarItem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CASESTUDY_API UAC_Hotbar : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAC_Hotbar();

	class UW_HotbarPanel* HotbarPanelWidget;

protected:
	virtual void BeginPlay() override;

	bool TryCreateWidget();

	bool TryBindInputs();

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* IA_HotbarNum1;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* IA_HotbarNum2;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* IA_HotbarNum3;

	UFUNCTION()
	void OnHotbarNum1();

	UFUNCTION()
	void OnHotbarNum2();

	UFUNCTION()
	void OnHotbarNum3();

	void TryToUseHotbarItem(int32 Index);

	UPROPERTY(EditDefaultsOnly, Category = "Widget")
	TSubclassOf<class UUserWidget> HotbarPanelWidgetClass;

public:
	bool AddItemToHotbar(AA_HotbarItem* HotbarItem);

	FOnHotbarItemAdded OnHotbarItemAdded;

	TArray<AA_HotbarItem*> Items;
};
