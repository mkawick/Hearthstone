
#include "Deck.h"
#include "Player.h"
#include <algorithm>    // std::random_shuffle
#include <iostream>
using namespace std;
#include "Global.h"

void	ApplySimpleCardTest( Player& attacker, Player& defender, const Deck& deck )
{
	attacker.SetupForNewGame( );
	defender.SetupForNewGame( );
	InitialzeDeckRandomly( attacker, deck );
	InitialzeDeckRandomly( defender, deck );
	attacker.PickNewHand( );
	defender.PickNewHand( );

	cout << "Defender: " << defender.GetName( ) << endl;
	defender.PrintState( );

	cout << "Attacker: " << attacker.GetName( ) << endl;
	attacker.PrintState( );

	cout << "Beginning game ..." << endl << endl << endl;
	//while ( )
	cout << "Defender: " << defender.GetName( ) << endl;
	defender.PrintAsOpponentState( );

	cout << "Attacker: " << attacker.GetName( ) << endl;
	cout << "attacker receives more mana " << endl;
	attacker.TurnSetup( 1 );
	cout << "attacker draws" << endl;
	attacker.DrawCard( true );
	attacker.PrintState( );

	cout << "picking card to play" << endl;
	Deck& attackerDeck = attacker.Gethand( );

	for ( int i = 0; i < attackerDeck.GetNumCards( ); i++ )// the number of cards may change
	{
		auto card = attackerDeck.GetCard( i );
		if ( card.m_manaCost <= attacker.GetMana( ) )
		{
			attacker.PlayCard( i, defender );
		}
	}
	cout << "//-------------------------------------------" << endl;
	cout << "Defender: " << defender.GetName( ) << endl;
	cout << "defender receives more mana " << endl;
	defender.TurnSetup( 1 );
	cout << "defender draws" << endl;
	defender.DrawCard( true );
	defender.PrintState( );

	cout << "picking card to play" << endl;
	Deck& defenderDeck = defender.Gethand( );

	for ( int i = 0; i < defenderDeck.GetNumCards( ); i++ )// the number of cards may change
	{
		auto card = defenderDeck.GetCard( i );
		if ( card.m_manaCost <= defender.GetMana( ) )
		{
			defender.PlayCard( i, attacker );
		}
	}
	cout << "//-------------------------------------------" << endl;

}