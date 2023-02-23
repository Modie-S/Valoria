// MaxiMod Games 2023
// Modie Shakarchi

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Characters/CharacterTypes.h"
#include "ValoriaAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class VALORIA_API UValoriaAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class AValoriaCharacter* ValoriaCharacter;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	class UCharacterMovementComponent* ValoriaCharacterMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float GroundSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool IsFalling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool IsInAir;

	UPROPERTY(BlueprintReadOnly, Category = "Movement | Character State")
	ECharacterState CharacterState;

	
	
};



