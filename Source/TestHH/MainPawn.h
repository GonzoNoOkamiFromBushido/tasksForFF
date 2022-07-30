
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SceneComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"
#include "GameStruct.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/AudioComponent.h"
#include "MainPawn.generated.h"

UCLASS()
class TESTHH_API AMainPawn : public APawn
{
	GENERATED_BODY()

public:
	
	AMainPawn();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
		int direction = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
		float TurnSpeed = 0.1f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|ModeParams")
		FturtleMoveParams TurtleParams;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		UParticleSystemComponent* ParticleForExist;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		UAudioComponent* AudioForExist;
private:
	FVector oldPos;
	FVector newPos;
	bool bMove = true; 
	bool bForward = true;
protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* MainBody;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		USceneComponent* SceneComp;
	

	

	FTimerHandle TimerMove;
	FTimerHandle TimerSwitchDir;

public:	
	void Move();
	void SwitchDir();
	void Init();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
