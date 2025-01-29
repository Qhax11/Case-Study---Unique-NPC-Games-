// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomerNPC.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void ACustomerNPC::BeginPlay()
{
	Super::BeginPlay();


}

void ACustomerNPC::MakeInteraction(AActor* InteractingActor)
{
	AAIController* AIController = Cast<AAIController>(GetController());
	if (AIController)
	{
		AIController->GetBlackboardComponent()->SetValueAsBool(TEXT("InteractedWithPlayer"), true);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AIController is NULL!"));
	}
}
