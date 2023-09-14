// Copyright Epic Games, Inc. All Rights Reserved.

#include "CollectGameMode.h"
#include "GameFramework/Actor.h"
#include "CollectCharacter.h"
#include "UObject/ConstructorHelpers.h"




ACollectGameMode::ACollectGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ACollectGameMode::BeginPlay() {

	Super::BeginPlay();
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &ACollectGameMode::SpawnPlayerRecharge, FMath::RandRange(1,2),true);

}

void ACollectGameMode::Tick(float DeltaTime) {


	Super::Tick(DeltaTime);
}

void ACollectGameMode::SpawnPlayerRecharge()
{
	float RandX = FMath::RandRange(Spawn_X_Min, Spawn_X_Max);

	float RandY = FMath::RandRange(Spawn_Y_Min, Spawn_Y_Max);

	FVector SpawnPosition = FVector(RandX, RandY, Spawn_Z);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

	GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);


}