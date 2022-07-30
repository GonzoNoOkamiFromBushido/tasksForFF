
#include "MainPawn.h"

AMainPawn::AMainPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	RootComponent = SceneComp;

	MainBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	MainBody->SetupAttachment(SceneComp);

	ParticleForExist = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PEffo"));
	AudioForExist = CreateDefaultSubobject<UAudioComponent>(TEXT("AEffo"));

	ParticleForExist->SetupAttachment(MainBody);
	AudioForExist->SetupAttachment(MainBody);
}

void AMainPawn::BeginPlay()
{
	Super::BeginPlay();

	ParticleForExist->ActivateSystem();
	AudioForExist->Play();
}

void AMainPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	oldPos = MainBody->GetComponentLocation();
	newPos = oldPos + (MainBody->GetForwardVector()*direction) * TurtleParams.speed * DeltaTime * (bool)TurtleParams.targetPoint * (bool)bMove;

	FRotator CurRot = MainBody->GetComponentRotation();
	FRotator TargetRot = UKismetMathLibrary::FindLookAtRotation(oldPos, TurtleParams.targetPoint->GetActorLocation());

	MainBody->SetWorldLocation(newPos);
	MainBody->SetWorldRotation(FMath::Lerp(CurRot, TargetRot, TurnSpeed));
}

void AMainPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMainPawn::Move()
{
	bMove ^= true;
	GetWorld()->GetTimerManager().SetTimer(TimerMove, this, &AMainPawn::Move, TurtleParams.MoveTime * bMove + TurtleParams.WaitTime * !bMove, true);
}

void AMainPawn::SwitchDir()
{
	direction *= -1;
	bForward ^= true;
	GetWorld()->GetTimerManager().SetTimer(TimerSwitchDir, this, &AMainPawn::SwitchDir, TurtleParams.MoveBackTime * !bForward + TurtleParams.MoveTime * bForward, true);
}

void AMainPawn::Init()
{
	if (TurtleParams.MoveWithBreake)
		Move();
	if (TurtleParams.MoveWithSwitchDir)
		SwitchDir();
}

