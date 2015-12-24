// Hearthstone.cpp : Defines the entry point for the console application.
//

#include "Deck.h"
#include "Player.h"
#include <assert.h>
#include <conio.h>
#include <random>
#include <algorithm>    // std::random_shuffle
#include <iostream>
using namespace std;
#pragma warning( disable:4996)



void	Print( const Deck& deck )
{
	int num = deck.GetNumCards();
	for( int i=0; i<num; i++ )
	{
		deck.GetCard( i ).PrintStats();
	}
}

void	RandomizeWithIndices(std::vector <int>& indices, int num)
{
	indices.clear();
	for (int i = 0; i<num; ++i) indices.push_back(i);
	std::random_shuffle(indices.begin(), indices.end());

	int count = 0;
	auto it = indices.begin();
	while (it != indices.end())
	{
		cout << count++ << " : " << (*it++) << endl;
	}
	cout << endl;
}
void	InitialzeDeckRandomly( Player& deckReceiver, const Deck& availableDeck )
{
	int num = availableDeck.GetNumCards();
	std::vector <int> indices;
	RandomizeWithIndices(indices, num);

	Deck& deck = deckReceiver.Getdeck();// acting directly on the data
	
	for ( auto it = indices.begin(); it != indices.end(); ++it )
	{
		deck.AddCard( availableDeck.GetCard( *it ) );
	}
}


void	InitialzeDeckInOrder(Player& deckReceiver, const Deck& availableDeck)
{
	int num = availableDeck.GetNumCards();

	Deck& deck = deckReceiver.Getdeck();// acting directly on the data
	deck.Clear();

	for (int i = 0; i < num; i++)
	{
		deck.AddCard(availableDeck.GetCard(i));
	}
}

//void	P
void	ApplySimpleCardTest(Player& attacker, Player& defender, const Deck& deck)
{
	attacker.SetupForNewGame();
	defender.SetupForNewGame();
	InitialzeDeckRandomly(attacker, deck);
	InitialzeDeckRandomly(defender, deck);
	attacker.PickNewHand();
	defender.PickNewHand();

	cout << "Defender: " << defender.GetName() << endl;
	defender.PrintState();

	cout << "Attacker: " << attacker.GetName() << endl;
	attacker.PrintState();

	cout << "Beginning game ..." << endl << endl << endl;
	//while ( )
	cout << "Defender: " << defender.GetName() << endl;
	defender.PrintAsOpponentState();

	cout << "Attacker: " << attacker.GetName() << endl;
	cout << "attacker receives more mana " << endl;
	attacker.TurnSetup( 1 );
	cout << "attacker draws" << endl; 
	attacker.DrawCard( true );
	attacker.PrintState();

	cout << "picking card to play" << endl;
	Deck& attackerDeck = attacker.Gethand();
	
	for ( int i = 0; i < attackerDeck.GetNumCards( ); i++ )// the number of cards may change
	{
		auto card = attackerDeck.GetCard(i);
		if (card.m_manaCost <= attacker.GetMana())
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

int FindCard( const Deck& deck, int damage, int heal, int numToDraw, int manaEarned )
{
	int num = deck.GetNumCards();
	auto cardList = deck.GetCardList();

	for ( int i = 0; i < num; i ++ )// I played with lots of different iterator types here and this is best
	{
		const Card& card = cardList[i];
		if ( card.GetDamage() == damage &&
			card.GetHealing() == heal &&
			card.GetNumToDraw() == numToDraw &&
			card.GetManaEarned() == manaEarned )
		{
			return  i;
		}
	} 


	return -1;// just for the compiler
}

int main( int argc, const char* argv[] )
{
	Deck deck;
	Player player1( "player1" ), player2( "player2" );

	deck.PrepStaticDeck();
	InitialzeDeckRandomly( player1, deck ); 
	InitialzeDeckRandomly( player2, deck );
	getch();

	ApplySimpleCardTest(player1, player2, deck);

	player1.PrintState( );

	player1.SetupForNewGame( );
	player2.PrintState( );
	player2.SetupForNewGame( );

	InitialzeDeckInOrder( player1, deck );
	InitialzeDeckInOrder( player2, deck );
	
	int cardIndex = FindCard( deck, 4, 0, 0, 1 );
	//Print(deck);
	//Print( player1.Getdeck() );
	//Print( player2.Getdeck() );


	getch();
	return 0;
}

