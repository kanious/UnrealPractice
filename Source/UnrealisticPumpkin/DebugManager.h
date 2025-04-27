// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "DebugManager.generated.h"


UCLASS()
class UNREALISTICPUMPKIN_API ADebugManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADebugManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	bool bIsDebugMode = false;
	void OnDebugTogglePressed();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Debug")
	int32 DebugMode;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Actions", meta = (AllowPrivateAccess = "true"))
	class UInputAction* IA_DebugToggle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Actions", meta = (AllowPrivateAccess = "true"))
	class UInputAction* IA_LeftCtrl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Mapping Context", meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* InputMappingContext;

};
