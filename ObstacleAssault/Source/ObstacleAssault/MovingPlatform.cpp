// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	start_location = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	FVector current_location = GetActorLocation();
	// traveled_distance >= 1000 ? current_location -= (velocity * DeltaTime) : current_location += (velocity * DeltaTime);
	// if (abs(traveled_distance) >= 5000)
	// {
	// 	current_location -= (velocity * DeltaTime);
	// }
	// else
	// {
	current_location += (velocity * DeltaTime);
	// }
	SetActorLocation(current_location);

	float traveled_distance = FVector::Dist(start_location, current_location);

	if (traveled_distance > move_distance)
	{
		FVector move_direction = velocity.GetSafeNormal();
		velocity = -velocity;
		start_location = start_location + move_direction * move_distance;
		SetActorLocation(start_location);
	}
}
