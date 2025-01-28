// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCBase.h"

ANPCBase::ANPCBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ANPCBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANPCBase::MakeInteraction()
{
	UE_LOG(LogTemp, Warning, TEXT("MAKED INTERACTION!"));
}



