// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AC_MakeInteractionAbility.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CASESTUDY_API UAC_MakeInteractionAbility : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAC_MakeInteractionAbility();

protected:
	virtual void BeginPlay() override;

	bool TryBindInput();

	void ActivateAbility();

	AActor* GetActorFromLineTrace();

	void MakeInteraction(AActor* InteractionalActor);

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* IA_MakeInteraction;

	UPROPERTY(EditDefaultsOnly, Category = "LineTrace")
	float LineTraceDebugDuration = 0.f;

	APawn* OwnerPawn;
};
