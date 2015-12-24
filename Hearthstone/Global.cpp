#include "Deck.h"
#include "Player.h"
#include <conio.h>

#include <algorithm>    // std::random_shuffle
#include <iostream>
using namespace std;
#include "Global.h"

void	Print( const Deck& deck )
{
	int num = deck.GetNumCards( );
	for ( int i = 0; i<num; i++ )
	{
		deck.GetCard( i ).PrintStats( );
	}
}

void	RandomizeWithIndices( std::vector <int>& indices, int num )
{
	indices.clear( );
	for ( int i = 0; i<num; ++i ) indices.push_back( i );
	std::random_shuffle( indices.begin( ), indices.end( ) );

	// only needed during debug
	/*	int count = 0;
	auto it = indices.begin();
	while (it != indices.end())
	{
	cout << count++ << " : " << (*it++) << endl;
	}*/
	cout << endl;
}
void	InitialzeDeckRandomly( Player& deckReceiver, const Deck& availableDeck )
{
	int num = availableDeck.GetNumCards( );
	std::vector <int> indices;
	RandomizeWithIndices( indices, num );

	Deck& deck = deckReceiver.Getdeck( );// acting directly on the data

	for ( auto it = indices.begin( ); it != indices.end( ); ++it )
	{
		deck.AddCard( availableDeck.GetCard( *it ) );
	}
}


void	InitialzeDeckInOrder( Player& deckReceiver, const Deck& availableDeck )
{
	int num = availableDeck.GetNumCards( );

	Deck& deck = deckReceiver.Getdeck( );// acting directly on the data
	deck.Clear( );

	for ( int i = 0; i < num; i++ )
	{
		deck.AddCard( availableDeck.GetCard( i ) );
	}
}

int FindCard( const Deck& deck, int damage, int heal, int numToDraw, int manaEarned )
{
	int num = deck.GetNumCards( );
	auto cardList = deck.GetCardList( );

	for ( int i = 0; i < num; i++ )// I played with lots of different iterator types here and this is best
	{
		const Card& card = cardList[i];
		if ( card.GetDamage( ) == damage &&
			card.GetHealing( ) == heal &&
			card.GetNumToDraw( ) == numToDraw &&
			card.GetManaEarned( ) == manaEarned )
		{
			return  i;
		}
	}


	return -1;// just for the compiler
}

void	WaitForUser( )
{
	cout << "press any key to continue" << endl;
	getch( );
}