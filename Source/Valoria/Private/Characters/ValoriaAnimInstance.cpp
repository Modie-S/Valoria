// MaxiMod Games 2023
// Modie Shakarchi


#include "Characters/ValoriaAnimInstance.h"
#include "Characters/ValoriaCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UValoriaAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

    ValoriaCharacter = Cast<AValoriaCharacter>(TryGetPawnOwner());
    
    if (ValoriaCharacter)
    {
        ValoriaCharacterMovement = ValoriaCharacter->GetCharacterMovement();
    }
}

void UValoriaAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

    if (ValoriaCharacterMovement)
    {
        GroundSpeed = UKismetMathLibrary::VSizeXY(ValoriaCharacterMovement->Velocity);
    }
}


