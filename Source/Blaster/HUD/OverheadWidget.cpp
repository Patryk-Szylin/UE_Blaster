// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString textToDisplay)
{
	if (DisplayText) 
	{
		DisplayText->SetText(FText::FromString(textToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	ENetRole LocalRole = InPawn->GetLocalRole();
	auto PlayerName = InPawn->GetPlayerState();
	
	FString role;
	FString localRole;

	switch (RemoteRole)
	{
		case ROLE_None:
			role = FString("None");
			break;
		case ROLE_SimulatedProxy:
			role = FString("Simulated Proxy");
			break;
		case ROLE_AutonomousProxy:
			role = FString("Autonomous Proxy");

			break;
		case ROLE_Authority:
			role = FString("Authority");
			break;
		case ROLE_MAX:
			role = FString("Max");
			break;
		default:
			break;
	}

	switch (LocalRole)
	{
		case ROLE_None:
			localRole = FString("None");
			break;
		case ROLE_SimulatedProxy:
			localRole = FString("Simulated Proxy");
			break;
		case ROLE_AutonomousProxy:
			localRole = FString("Autonomous Proxy");

			break;
		case ROLE_Authority:
			localRole = FString("Authority");
			break;
		case ROLE_MAX:
			localRole = FString("Max");
			break;
		default:
		break;
	}

	FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *role);
	FString LocalRoleString = FString::Printf(TEXT("Local Role: %s"), *localRole);
	SetDisplayText(LocalRoleString);
}

void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	RemoveFromParent();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}
