// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "W_InteractionPopUp.generated.h"

class UButton;

UCLASS()
class CASESTUDY_API UW_InteractionPopUp : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct();

	void CustomInitialize(ACharacter* OwnerChar);

	UFUNCTION()
	void OnPlayAnimationButtonClicked();

	UFUNCTION()
	void OnSayHiButtonClicked();

	UFUNCTION()
	void OnTakeItemButtonClicked();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> B_PlayAnimationButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> B_SayHiButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> B_TakeItemButton;

	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* Montage;

	class ASellerNPC* OwnerNPC;
};
