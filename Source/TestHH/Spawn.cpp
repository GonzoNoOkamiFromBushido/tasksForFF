
#include "Spawn.h"

ASpawn::ASpawn()
{
	PrimaryActorTick.bCanEverTick = true;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	
	SpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("Spawn point"));
	SpawnPoint->SetupAttachment(Body);

	ButtonBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonBody"));
	ButtonBody->SetupAttachment(Body);

	BoxCom = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Trigger"));
	BoxCom->SetupAttachment(ButtonBody);

	ButtonText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));
	ButtonText->SetupAttachment(ButtonBody);

	BoxCom->OnComponentBeginOverlap.AddDynamic(this, &ASpawn::OnBeginOverlap);

	ParticleForStart = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PEffo"));
	AudioForStart = CreateDefaultSubobject<UAudioComponent>(TEXT("AEffo"));

	ParticleForStart->SetupAttachment(Body);
	AudioForStart->SetupAttachment(Body);
}

void ASpawn::BeginPlay()
{
	Super::BeginPlay();
}

void ASpawn::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		Spawn();
		ParticleForStart->ActivateSystem();
		AudioForStart->Play();
	}
}

void ASpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpawn::Spawn()
{
	Pawn = GetWorld()->SpawnActor<AMainPawn>(Class, SpawnPoint->GetComponentLocation(), SpawnPoint->GetComponentRotation());

	if (Pawn)
	{
		Pawn->TurtleParams = Turtle;
		Pawn->Init();
	}
}

