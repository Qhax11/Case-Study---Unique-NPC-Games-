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

	void PlayPopUpMontage();

	void GiveHavedHotbarItemToPlayer();

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> InteractionPopUpClass;

	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* PopUpMontage;

	UPROPERTY(EditAnyWhere)
	TSubclassOf<AA_HotbarItem> HotbarItemClass;

	AActor* PlayerActorRef;
};
