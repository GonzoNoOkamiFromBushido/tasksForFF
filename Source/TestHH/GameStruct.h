// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameStruct.generated.h"

USTRUCT(Blueprintable)
struct FturtleMoveParams
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|Timer")
		float WaitTime = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|Timer")
		float MoveTime = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|Timer")
		float MoveBackTime = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|Mode")
		bool MoveWithBreake;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|Mode")
		bool MoveWithSwitchDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|Target")
		AActor* targetPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|Speed")
		float speed = 40;
};