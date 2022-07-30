
#include "EndPoint.h"

AEndPoint::AEndPoint()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	RootComponent = SceneComp;
	
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(SceneComp);
	
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetupAttachment(Body);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AEndPoint::OnBeginOverlap);
	
	TextButton = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextComp"));
	TextButton->SetupAttachment(Body);

	ParticleForEnd = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PEffo"));
	AudioForEnd = CreateDefaultSubobject<UAudioComponent>(TEXT("AEffo"));

	ParticleForEnd->SetupAttachment(Body);
	AudioForEnd->SetupAttachment(Body);


	
}

void AEndPoint::BeginPlay()
{
	Super::BeginPlay();
}

void AEndPoint::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AMainPawn>(OtherActor))
	{
		OtherActor->Destroy();
		ParticleForEnd->ActivateSystem();
		AudioForEnd->Play();
	}
}

void AEndPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

