// Fill out your copyright notice in the Description page of Project Settings.


#include "Pellets.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
APellets::APellets()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APellets::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APellets::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APellets::Consume()
{
	UGameplayStatics::PlaySound2D(this, ConsumptionSound);

	PelletsEatenEvent.Broadcast(PelletsType);

	Destroy();

}
