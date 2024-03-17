// MaxiMod Games 2024
// Modie Shakarchi
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HitInterface.h"
#include "DestructibleActor.generated.h"

class UGeometryCollectionComponent;

UCLASS()
class VALORIA_API ADestructibleActor : public AActor, public IHitInterface
{
	GENERATED_BODY()

public:

	ADestructibleActor();

	virtual void Tick( float DeltaTime ) override;

	virtual void GetHit_Implementation( const FVector& ImpactPoint ) override;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY( VisibleAnywhere )
	UGeometryCollectionComponent* GeometryCollection;

};
