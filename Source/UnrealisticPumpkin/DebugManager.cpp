// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugManager.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ADebugManager::ADebugManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsDebugMode = false;
	DebugMode = 0;
}

// Called when the game starts or when spawned
void ADebugManager::BeginPlay()
{
	Super::BeginPlay();
	
	//UE_LOG(LogTemp, Warning, TEXT("Hello Pumpkin4"));

	if (APlayerController* controller = GetWorld()->GetFirstPlayerController())
	{
		EnableInput(controller);

		// EnhancedInputSubsystem¿¡ MappingContext Ãß°¡
		if (ULocalPlayer* loPlayer = controller->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* subSystem = loPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (InputMappingContext)
				{
					subSystem->AddMappingContext(InputMappingContext, 0);
				}
			}
		}

		// InputComponent Action Bind
		if (UEnhancedInputComponent* comp = Cast<UEnhancedInputComponent>(InputComponent))
		{
			if (IA_DebugToggle)
			{
				comp->BindAction(IA_DebugToggle, ETriggerEvent::Started, this, &ADebugManager::OnDebugTogglePressed);
			}
		}
	}
}

// Called every frame
void ADebugManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADebugManager::OnDebugTogglePressed()
{
	//UE_LOG(LogTemp, Warning, TEXT("Left Control + D down"));

	if (bIsDebugMode)
	{
		bIsDebugMode = false;
		DebugMode = 0;
	}
	else
	{
		bIsDebugMode = true;
		DebugMode = 1;
	}
}
