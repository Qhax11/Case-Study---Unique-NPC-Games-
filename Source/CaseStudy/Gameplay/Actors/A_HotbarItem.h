// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CaseStudy/Gameplay/Interfaces/I_Interaction.h"
#include "A_HotbarItem.generated.h"

USTRUCT(BlueprintType)
struct FHotbarItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "HotbarItemData")
	FText Name;

	UPROPERTY(EditDefaultsOnly, Category = "HotbarItemData")
	UTexture2D* Image;

	FHotbarItemData() = default;

	FHotbarItemData(FText InName, UTexture2D* InImage)
		: Name(InName),
		Image(InImage)
	{}
};

UCLASS()
class CASESTUDY_API AA_HotbarItem : public AActor, public II_Interaction
{
	GENERATED_BODY()
	
public:	
	AA_HotbarItem();

	UPROPERTY(EditDefaultsOnly)
	FHotbarItemData ItemData;

protected:
	virtual void BeginPlay() override;

	virtual void MakeInteraction(AActor* InteractingActor);

	void AddToHotbar(AActor* InteractingActor);

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;
};
