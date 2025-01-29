// Fill out your copyright notice in the Description page of Project Settings.


#include "A_HotbarItem.h"
#include "CaseStudy/Gameplay/Characters/Player/Components/AC_Hotbar.h"

AA_HotbarItem::AA_HotbarItem()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AA_HotbarItem::BeginPlay()
{
	Super::BeginPlay();
}

void AA_HotbarItem::MakeInteraction(AActor* InteractingActor)
{
	GoToHotbar(InteractingActor);
}

void AA_HotbarItem::GoToHotbar(AActor* InteractingActor)
{
	if (UAC_Hotbar* InteractingActorHotbarComp = Cast<UAC_Hotbar>(InteractingActor->GetComponentByClass(UAC_Hotbar::StaticClass())))
	{
		if (InteractingActorHotbarComp->AddHotbarItem(this))
		{
			//Destroy();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Hotbar component couldn't add this Hotbar Item: %s"), *GetName());
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Hotbar component couldn't find in: %s"), *GetName());
	}
}


