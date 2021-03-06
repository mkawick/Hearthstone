
#include "Deck.h"
#include "Player.h"
#include <algorithm>    // std::random_shuffle
#include <iostream>
using namespace std;
#include "Global.h"

//----------------------------------------------------------------

// just system tests to prove out basic functionality
void	ApplySimpleCardTest( Player& attacker, Player& defender, const Deck& deck )
{
	attacker.SetupForNewGame();
	defender.SetupForNewGame();
	Global::InitialzeDeckRandomly( attacker, deck );
	Global::InitialzeDeckRandomly( defender, deck );
	attacker.PickNewHand();
	defender.PickNewHand();

	cout << "Defender: " << defender.GetName() << endl;
	defender.PrintState();

	cout << "Attacker: " << attacker.GetName() << endl;
	attacker.PrintState();

	cout << "Beginning game ..." << endl << endl << endl;
	//while ()
	cout << "Defender: " << defender.GetName() << endl;
	defender.PrintAsOpponentState();

	cout << "Attacker: " << attacker.GetName() << endl;
	cout << "attacker receives more mana " << endl;
	attacker.SetupForNextTurn( 1 ); // design doc #8
	cout << "attacker draws" << endl;
	attacker.DrawCard( true );
	attacker.PrintState();

	cout << "picking card to play" << endl;
	Deck& attackerDeck = attacker.GetHand();

	for ( int i = 0; i < attackerDeck.GetNumCards(); ++i )// the number of cards may change
	{
		auto card = Global::GetCardFromDictionary( attackerDeck.GetCard( i ) );
		if ( card.GetCost() <= attacker.GetMana() )
		{
			attacker.PlayCard( i, defender );
		}
	}
	cout << "//-------------------------------------------" << endl;
	cout << "Defender: " << defender.GetName() << endl;
	cout << "defender receives more mana " << endl;
	defender.SetupForNextTurn( 1 );
	cout << "defender draws" << endl;
	defender.DrawCard( true );
	defender.PrintState();

	cout << "picking card to play" << endl;
	Deck& defenderDeck = defender.GetHand();

	for ( int i = 0; i < defenderDeck.GetNumCards(); ++i )// the number of cards may change
	{
		auto card = Global::GetCardFromDictionary( defenderDeck.GetCard( i ) );
		if ( card.GetCost() <= defender.GetMana() )
		{
			defender.PlayCard( i, attacker );
		}
	}
	cout << "//-------------------------------------------" << endl;

}

//----------------------------------------------------------------

void	ApplySimpleCardTest2( Player& player1, Player& player2, const Deck& deck )
{
	player1.SetupForNewGame();
	player2.PrintState();
	player2.SetupForNewGame();

	Global::InitialzeDeckInOrder( player1, deck );
	Global::InitialzeDeckInOrder( player2, deck );

	int cardIndex = Global::FindCardInDictionary( 5, 4, 0, 0, 1 );
	player1.GiveMana( 128 );
	player2.GiveMana( 1 );

	for ( int i = 0; i < 7; ++i ) // kill player 2
		Global::GetCardFromDictionary( Global::FindCardInDictionary( 5, 4, 0, 0, 1 ) ).Play( player1, player2 );// damage

	Global::GetCardFromDictionary( Global::FindCardInDictionary( 2, 0, 2, 0, 0 ) ).Play( player1, player2 );// healing
	Global::GetCardFromDictionary( Global::FindCardInDictionary( 2, 0, 2, 0, 0 ) ).Play( player2, player1 );// healing

	Global::GetCardFromDictionary( Global::FindCardInDictionary( 5, 4, 0, 0, 1 ) ).Play( player1, player2 );// damage


	/*	player1.ApplyCard( Global::GetCardFromDictionary( Global::FindCardInDictionary( 5, 4, 0, 0, 1 ) ), player2 );// damage

	player1.ApplyCard( Global::GetCardFromDictionary( Global::FindCardInDictionary( 2, 0, 2, 0, 0 ) ), player2 );// healing
	player2.ApplyCard( Global::GetCardFromDictionary( Global::FindCardInDictionary( 2, 0, 2, 0, 0 ) ), player1 );

	player1.ApplyCard( Global::GetCardFromDictionary( Global::FindCardInDictionary( 5, 4, 0, 0, 1 ) ), player2 );// damage*/
}

//----------------------------------------------------------------
//----------------------------------------------------------------
