// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CaseStudy/Gameplay/Interfaces/I_Interaction.h"
#include "NPCBase.generated.h"

UCLASS()
class CASESTUDY_API ANPCBase : public ACharacter, public II_Interaction
{
	GENERATED_BODY()

public:
	ANPCBase();

protected:
	virtual void BeginPlay() override;

	virtual void MakeInteraction();


};
