// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"
#include "Engine/Public/DrawDebugHelpers.h"
#include "GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	reach = 100.0f;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	owner = GetOwner();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	FVector playerPosition;
	FRotator playerRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT playerPosition, OUT playerRotation);

	//UE_LOG(LogTemp, Warning, TEXT("position: %s and rotation: %s"), *(playerPosition.ToString()), *(playerRotation.ToString()));

	FVector viewDirection = playerRotation.Vector();
	FVector target = playerPosition + viewDirection * reach;

	DrawDebugLine(GetWorld(), playerPosition, target, FColor::Red);

	FCollisionQueryParams traceParams(FName(TEXT("")), false, GetOwner());

	FHitResult hit;
	GetWorld()->LineTraceSingleByObjectType(OUT hit, playerPosition, target, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), traceParams);

	AActor* hitActor = hit.GetActor();

	if (hitActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("hit actor %s"), *(hitActor->GetName()));
	}
}

