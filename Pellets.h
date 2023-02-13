// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pellets.generated.h"

class USoundCue;

// enumerator class - can be used to compare two different types of actors. Like a powerup pellet compared to a regular pellet in Pac Man.
UENUM(BlueprintType)
enum class EPelletsType : uint8 
{
	Regular,
	PowerUP

};

// A delegate is like a subscription service. This one has three parts. One event (service), two types (subscribers). Calling the delegate event will "inform" all subscribers. 
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPelletsEatenEvent, EPelletsType, PelletsType);

UCLASS()
class LEARNINGCPP3_API APellets : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APellets();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Consume();

	UPROPERTY(EditAnywhere)
		EPelletsType PelletsType = EPelletsType::Regular;

	// We can assign and call within a blueprint.
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FPelletsEatenEvent PelletsEatenEvent;

private:

	UPROPERTY(EditAnywhere)
		USoundCue* ConsumptionSound;

};
