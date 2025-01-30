// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CaseStudy/Gameplay/Characters/NPC/NPCBase.h"
#include "CustomerNPC.generated.h"

/**
 * 
 */
UCLASS()
class CASESTUDY_API ACustomerNPC : public ANPCBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void MakeInteraction(AActor* InteractingActor);

};
