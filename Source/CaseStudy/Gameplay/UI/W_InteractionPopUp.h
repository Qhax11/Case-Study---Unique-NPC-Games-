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

	ACharacter* OwnerCharacter;

	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* Montage;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> PlayAnimationButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> SayHiButton;

	UFUNCTION()
	void OnPlayAnimationButtonClicked();

	UFUNCTION()
	void OnSayHiButtonClicked();
};
