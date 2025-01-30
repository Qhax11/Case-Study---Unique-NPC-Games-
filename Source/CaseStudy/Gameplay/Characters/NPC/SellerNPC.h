// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CaseStudy/Gameplay/Characters/NPC/NPCBase.h"
#include "SellerNPC.generated.h"

class AA_HotbarItem;

UCLASS()
class CASESTUDY_API ASellerNPC : public ANPCBase
{
	GENERATED_BODY()

public:
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

	UPROPERTY(EditAnyWhere)
	TSubclassOf<AA_HotbarItem> HotbarItemClass;

	AActor* Player;
};
