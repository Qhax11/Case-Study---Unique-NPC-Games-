// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CaseStudy/Gameplay/Interfaces/I_Interaction.h"
#include "NPCBase.generated.h"

class AA_HotbarItem;

UCLASS()
class CASESTUDY_API ANPCBase : public ACharacter, public II_Interaction
{
	GENERATED_BODY()

public:
	ANPCBase();

protected:
	virtual void BeginPlay() override;

	virtual void MakeInteraction(AActor* InteractingActor);

	bool CreatePopUpWidget();

public:
	void PlayPopUpMontage();

	void GiveHavedHotbarItemToPlayer();

	UPROPERTY(EditDefaultsOnly, Category = "Interaction")
	TSubclassOf<class UUserWidget> InteractionPopUpClass;

	// Montage that play on PopUp button.
	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* PopUpMontage;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AA_HotbarItem> HotbarItemClass;

	AActor* Player;
};
