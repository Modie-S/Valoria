// MaxiMod Games 2023
// Modie Shakarchi


#include "Characters/ValoriaCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Items/Item.h"
#include "Items/Weapons/Weapon.h"
#include "Animation/AnimMontage.h"


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
	if (ActionState == EActionState::EAS_Attacking) return;
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
	if (ActionState == EActionState::EAS_Attacking) return;
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

void AValoriaCharacter::EKeyPressed()
{
	AWeapon* OverlappingWeapon = Cast<AWeapon>(OverlappingItem);
	if (OverlappingWeapon)
	{
		OverlappingWeapon->Equip(GetMesh(), FName("RightHandSocket"));
		CharacterState = ECharacterState::ECS_EquippedOneHandedWeapon;
	}
}

void AValoriaCharacter::Attack()
{
	if (CanAttack())
	{
		PlayAttackMontage();
		ActionState = EActionState::EAS_Attacking;
	}
}

bool AValoriaCharacter::CanAttack()
{
	return ActionState == EActionState::EAS_Unoccupied && 
			CharacterState != ECharacterState::ECS_Unequipped;
}

void AValoriaCharacter::PlayAttackMontage()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && AttackMontage && CharacterState == ECharacterState::ECS_EquippedOneHandedWeapon)
	{
		AnimInstance->Montage_Play(AttackMontage);
		const int32 Selection = FMath::RandRange(0, 2);
		FName SectionName = FName();
		switch (Selection)
		{
			case 0:
				SectionName = FName("Attack1");
				break;
			case 1:
				SectionName = FName("Attack2");
				break;
			case 2:
				SectionName = FName("Attack3");
				break;
			default:
				break;
		}
		AnimInstance->Montage_JumpToSection(SectionName, AttackMontage);
	}
}

void AValoriaCharacter::AttackEnd()
{
	ActionState = EActionState::EAS_Unoccupied;
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

	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(FName("Equip"), IE_Pressed, this, &AValoriaCharacter::EKeyPressed);
	PlayerInputComponent->BindAction(FName("Attack"), IE_Pressed, this, &AValoriaCharacter::Attack);

}

