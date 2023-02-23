// MaxiMod Games 2023
// Modie Shakarchi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Characters/CharacterTypes.h"
#include "ValoriaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AItem;

UCLASS()
class VALORIA_API AValoriaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AValoriaCharacter();

protected:
	
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void EKeyPressed();

private:

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

public:	
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
};







