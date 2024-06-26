// MaxiMod Games 2024
// Modie Shakarchi

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Treasure.generated.h"

/**
 * 
 */
UCLASS()
class VALORIA_API ATreasure : public AItem
{
	GENERATED_BODY()

protected:

	virtual void OnSphereOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult ) override;

private:

	UPROPERTY( EditAnywhere, Category = "Sounds" )
	USoundBase* CollectSound;
	
};
