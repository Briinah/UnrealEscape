// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"

#include "OpenDoor.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	void Open();
	void Close();

	bool isOpen = false;

	//UPROPERTY(VisibleAnywhere)
	UPROPERTY(EditAnywhere)
	float closeTime = 5.0f;
	float openTime;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* pressurePlate;

	AActor* triggeringActor;

	AActor* owner;
};
