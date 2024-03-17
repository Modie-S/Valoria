// MaxiMod Games 2023
// Modie Shakarchi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Enemy.generated.h"

class UAnimMontage;

UCLASS()
class VALORIA_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:

	AEnemy();

protected:

	virtual void BeginPlay() override;

	//
	// Playing montages
	//
	void PlayHitReactMontage( const FName& SectionName );

private:

	//
	// Animation Montages
	//
	UPROPERTY( EditDefaultsOnly, Category = "Montages" )
	UAnimMontage* HitReactMontage;

	UPROPERTY( EditAnywhere, Category = "Sounds" )
	USoundBase* HitSound;

	UPROPERTY( EditAnywhere, Category = "Visual Effects" )
	UParticleSystem* HitParticles;


public:

	virtual void Tick( float DeltaTime ) override;
	virtual void SetupPlayerInputComponent( class UInputComponent* PlayerInputComponent ) override;

	virtual void GetHit_Implementation( const FVector& ImpactPoint ) override;

	void DirectionalHitReact( const FVector& ImpactPoint );

};



