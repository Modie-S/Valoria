// MaxiMod Games 2024
// Modie Shakarchi


#include "Destructible/DestructibleActor.h"
#include "GeometryCollection/GeometryCollectionComponent.h"

ADestructibleActor::ADestructibleActor()
{
	PrimaryActorTick.bCanEverTick = false;

	GeometryCollection = CreateDefaultSubobject< UGeometryCollectionComponent >( TEXT( "GeometryCollection" ) );
	SetRootComponent( GeometryCollection );
	GeometryCollection->SetGenerateOverlapEvents( true );
	GeometryCollection->SetCollisionResponseToChannel( ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore );
}

void ADestructibleActor::BeginPlay()
{
	Super::BeginPlay();

}

void ADestructibleActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ADestructibleActor::GetHit_Implementation( const FVector& ImpactPoint )
{

}

