#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainPawn.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/BoxComponent.h"
#include "GameStruct.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/AudioComponent.h"
#include "Spawn.generated.h"

UCLASS()
class TESTHH_API ASpawn : public AActor
{
	GENERATED_BODY()
	
public:	

	ASpawn();
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Body;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
		UArrowComponent* SpawnPoint;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* ButtonBody;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		UBoxComponent* BoxCom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button text")
		UTextRenderComponent* ButtonText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParamForSpawn")
		FturtleMoveParams Turtle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParamForSpawn")
		TSubclassOf<AMainPawn> Class;
	UPROPERTY()
		AMainPawn* Pawn;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		UParticleSystemComponent* ParticleForStart;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		UAudioComponent* AudioForStart;


protected:
	
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void Tick(float DeltaTime) override;
	void Spawn();

};
