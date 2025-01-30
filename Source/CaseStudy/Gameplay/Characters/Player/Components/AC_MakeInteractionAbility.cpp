// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_MakeInteractionAbility.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "CaseStudy/Gameplay/Interfaces/I_Interaction.h"


UAC_MakeInteractionAbility::UAC_MakeInteractionAbility()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_MakeInteractionAbility::BeginPlay()
{
	Super::BeginPlay();

	OwnerPawn = Cast<APawn>(GetOwner());
	if (!OwnerPawn) 
	{
		UE_LOG(LogTemp, Warning, TEXT("APawn cast is failed in: %s"), *GetName());
		return;
	}

	if (!TryBindInput()) 
	{
		UE_LOG(LogTemp, Warning, TEXT("TryBindInput is failed"));
	}
}

bool UAC_MakeInteractionAbility::TryBindInput()
{
	if (UEnhancedInputComponent* OwnerEnhancedInputComp = Cast<UEnhancedInputComponent>(GetOwner()->InputComponent)) 
	{
		OwnerEnhancedInputComp->BindAction(IA_MakeInteraction, ETriggerEvent::Triggered, this, &UAC_MakeInteractionAbility::ActivateAbility);
		return true;
	}

	return false;
}

void UAC_MakeInteractionAbility::ActivateAbility()
{
	AActor* ActorFromLineTrace = GetActorFromLineTrace();
	CallInteraction(ActorFromLineTrace);
}

AActor* UAC_MakeInteractionAbility::GetActorFromLineTrace()
{
	if (!OwnerPawn)
	{
		return nullptr;
	}

	FVector EyesViewPoint;
	FRotator EyesViewRot;
	FHitResult HitResult;

	OwnerPawn->GetController()->GetActorEyesViewPoint(EyesViewPoint, EyesViewRot);

	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(EyesViewRot) * 1000;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(OwnerPawn);

	GetWorld()->LineTraceSingleByChannel(HitResult, EyesViewPoint, EyesViewPoint + ForwardVector, ECollisionChannel::ECC_WorldDynamic, QueryParams);

	DrawDebugLine(
		GetWorld(),
		EyesViewPoint,
		EyesViewPoint + ForwardVector,
		FColor::Black,
		false,
		LineTraceDebugDuration,
		0,
		2.0f
	);

	return HitResult.GetActor();
}

void UAC_MakeInteractionAbility::CallInteraction(AActor* InteractionalActor)
{
	if (II_Interaction* InteractionInterface = Cast<II_Interaction>(InteractionalActor))
	{
		InteractionInterface->MakeInteraction(GetOwner());
	}
}



