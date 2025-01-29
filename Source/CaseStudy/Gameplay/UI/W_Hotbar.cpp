// Fill out your copyright notice in the Description page of Project Settings.


#include "W_Hotbar.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "CaseStudy/Gameplay/Actors/A_HotbarItem.h"
#include "Kismet/KismetTextLibrary.h"


void UW_Hotbar::AddHotbarData(FHotbarItemData& HotbarItemData)
{
	T_HotbarItemName->SetText(HotbarItemData.Name);
	IMG_HotbarItemImage->SetBrushFromTexture(HotbarItemData.Image);
	bIsValid = true;
}

void UW_Hotbar::SetInputNum(int32 InputNum)
{
	T_InputNum->SetText(UKismetTextLibrary::Conv_IntToText(InputNum));
}
