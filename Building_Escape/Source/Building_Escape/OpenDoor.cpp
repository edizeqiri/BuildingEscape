// Copyright Edi Zeqiri 2021


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

UOpenDoor::UOpenDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	TargetYaw += InitialYaw;

	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has the OpenDoor on it, but no PressurePlate set!"), *GetOwner()->GetName());
	}

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->
	GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->
	GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetWorld()->
	GetFirstPlayerController()->GetPawn();
}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor(DeltaTime);
	}
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
		CurrentYaw = GetOwner()->GetActorRotation().Yaw;
		FRotator OpenDoor(0.f,TargetYaw,0.f);
		OpenDoor.Yaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2);
		GetOwner()->SetActorRotation(OpenDoor);
}

