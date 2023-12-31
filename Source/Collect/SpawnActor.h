// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnActor.generated.h"

UCLASS()
class COLLECT_API ASpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnActor();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:



	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcess = "true"))
	TSubclassOf<AActor> ActorToSpawn;

};
