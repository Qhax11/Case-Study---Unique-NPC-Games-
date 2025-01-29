// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CaseStudy/Gameplay/Interfaces/I_Interaction.h"
#include "A_HotbarItem.generated.h"

UCLASS()
class CASESTUDY_API AA_HotbarItem : public AActor, public II_Interaction
{
	GENERATED_BODY()
	
public:	
	AA_HotbarItem();

protected:
	virtual void BeginPlay() override;

	virtual void MakeInteraction(AActor* InteractingActor);

	void GoToHotbar(AActor* InteractingActor);

};
