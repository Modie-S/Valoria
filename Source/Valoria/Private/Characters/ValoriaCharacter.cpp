// MaxiMod Games 2023
// Modie Shakarchi


#include "Characters/ValoriaCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


AValoriaCharacter::AValoriaCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);

}


void AValoriaCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AValoriaCharacter::MoveForward(float Value)
{
	if (Controller && (Value != 0))
	{
		// find which way is forward according to controller rotation
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}

}

void AValoriaCharacter::MoveRight(float Value)
{
	if (Controller && (Value != 0))
	{
		// find which way is right
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AValoriaCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AValoriaCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AValoriaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AValoriaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AValoriaCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &AValoriaCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AValoriaCharacter::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AValoriaCharacter::LookUp);

}

