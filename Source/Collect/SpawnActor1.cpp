// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnActor1.h"

// Sets default values
ASpawnActor1::ASpawnActor1()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnActor1::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &ASpawnActor1::SpawnActor, 12.0f, true);
}




// Called every frame
void ASpawnActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnActor1::SpawnActor()
{
	const FVector Location = GetActorLocation();
	const FRotator Rotation = GetActorRotation();

	GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation);
}