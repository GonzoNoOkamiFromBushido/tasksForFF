
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/SceneComponent.h"
#include "MainPawn.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/AudioComponent.h"
#include "EndPoint.generated.h"

UCLASS()
class TESTHH_API AEndPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AEndPoint();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* Body;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		UBoxComponent* BoxComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		USceneComponent* SceneComp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
		UTextRenderComponent* TextButton;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		UParticleSystemComponent* ParticleForEnd;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		UAudioComponent* AudioForEnd;
protected:
	
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void Tick(float DeltaTime) override;

};
