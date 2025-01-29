// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Interface.h"
#include "I_Interaction.generated.h"


UINTERFACE(MinimalAPI)
class UI_Interaction : public UInterface
{
	GENERATED_BODY()
};

class II_Interaction
{
	GENERATED_IINTERFACE_BODY()

public:

	virtual void MakeInteraction(AActor* InteractingActor) {}

};