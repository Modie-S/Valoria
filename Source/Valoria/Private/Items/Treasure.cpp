// MaxiMod Games 2024
// Modie Shakarchi

#include "Items/Treasure.h"
#include "Characters/ValoriaCharacter.h"
#include "Kismet/GameplayStatics.h"


void ATreasure::OnSphereOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult )
{
	AValoriaCharacter* ValoriaCharacter = Cast<AValoriaCharacter>( OtherActor );
	if ( ValoriaCharacter )
	{
		if( CollectSound )
		{
			UGameplayStatics::PlaySoundAtLocation( this, CollectSound, GetActorLocation() );
		}

		Destroy();
	}
}
