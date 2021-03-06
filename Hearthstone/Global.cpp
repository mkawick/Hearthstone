#include "Deck.h"
#include "Player.h"
#include <conio.h>
#include <assert.h>

#include <algorithm>    // std::random_shuffle
#include <iostream>
using namespace std;
#include "Global.h"
#pragma warning( disable:4996)
using namespace Global;

CardDictionary		globalCardDictionary;

//----------------------------------------------------------------

void	Global::Print( const Deck& deck )
{
	int num = deck.GetNumCards();
	for ( int i = 0; i<num; ++i )
	{
		GetCardFromDictionary( deck.GetCard( i ) ).PrintStats();
	}
}

//----------------------------------------------------------------

void	Global::RandomizeWithIndices( std::vector <int>& indices, int num )
{
	indices.clear();
	for ( int i = 0; i<num; ++i ) 
		indices.push_back( i );

	std::random_shuffle( indices.begin(), indices.end() );

	// only needed during debug
#ifdef TESTING
	int count = 0;
	auto it = indices.begin();
	while (it != indices.end())
	{
		cout << count++ << " : " << (*it) << endl;
		++it;
	}
#endif

	cout << endl;
}

//----------------------------------------------------------------

void	Global::InitialzeDeckRandomly( Player& deckReceiver, const Deck& availableDeck )
{
	assert( Global::IsGlobalDeckLoaded() == true );

	int num = availableDeck.GetNumCards();
	std::vector <int> indices;
	Global::RandomizeWithIndices( indices, num );

	Deck& deck = deckReceiver.GetDeck();// acting directly on the data

	for ( auto it = indices.begin(); it != indices.end(); ++it )
	{
		deck.AddCard( availableDeck.GetCard( *it ) );
	}
}

//----------------------------------------------------------------

void	Global::InitialzeDeckInOrder( Player& deckReceiver, const Deck& availableDeck )
{
	assert( Global::IsGlobalDeckLoaded() == true );

	int num = availableDeck.GetNumCards();

	Deck& deck = deckReceiver.GetDeck();// acting directly on the data
	deck.Clear();

	for ( int i = 0; i < num; ++i )
	{
		deck.AddCard( availableDeck.GetCard( i ) );
	}
}

//----------------------------------------------------------------

int		Global::ChooseRandomNumber( int rangeMin, int rangeMax )
{
	// I realize that this is imperfect for random number generation
	// but it makes testing easier since the numbers are always the same

	return rand() % (rangeMax - rangeMin) + rangeMin;
	
	// this is much better using c++ 11 random
}

//----------------------------------------------------------------

void	Global::WaitForUser()
{
	cout << "press any key to continue" << endl;
	getch();
}

//----------------------------------------------------------------

bool	Global::IsGlobalDeckLoaded()
{
	return globalCardDictionary.GetNumCards() > 0;
}

//----------------------------------------------------------------

// this should be read in from a file or some other data source. But given the specifics of the design doc...
void	Global::PrepGlobalDeck()  // design doc #2
{
	Card card_a( 1, 1, 0, 0, 0, "deal 1 damage and cost 1 mana" );
	globalCardDictionary.AddCard( card_a );

	Card card_b( 2, 2, 0, 0, 0, "deal 2 damage and cost 2 mana" );
	globalCardDictionary.AddCard( card_b );

	Card card_c( 3, 3, 0, 0, 0, "deal 3 damage and cost 3 mana" );
	globalCardDictionary.AddCard( card_c );

	Card card_d( 4, 4, 0, 0, 0, "deal 4 damage and cost 4 mana" );
	globalCardDictionary.AddCard( card_d );

	Card card_e( 5, 5, 0, 0, 0, "deal 5 damage and cost 5 mana" );
	globalCardDictionary.AddCard( card_e );

	Card card_f( 1, 0, 1, 0, 0, "heal 1 hit points and cost 1 mana" );// I renamed this to make is more obvious in the logging.. 'heal' and 'deal' look the same in a wall of text
	globalCardDictionary.AddCard( card_f );

	Card card_g( 2, 0, 2, 0, 0, "heal 2 hit points and cost 2 mana" );
	globalCardDictionary.AddCard( card_g );

	Card card_h( 1, 1, 0, 1, 0, "deal 1 damage, cost 1 mana, draw 1 card" );
	globalCardDictionary.AddCard( card_h );

	Card card_i( 5, 4, 0, 0, 1, "deal 4 damage, cost 5 mana, return 1 mana, output message" );
	card_i.AddMessage( "You will never defeat me!" );
	globalCardDictionary.AddCard( card_i );
}

//----------------------------------------------------------------

int		Global::GetDictionarySize()
{
	return globalCardDictionary.GetNumCards();
}

//----------------------------------------------------------------

const Card& Global::GetCardFromDictionary( int index )
{
	assert( index < globalCardDictionary.GetNumCards() );
	if ( index >= globalCardDictionary.GetNumCards() )
	{
		cout << "ERROR: Bad card index. " << endl;
		return globalCardDictionary.GetCard(0);
	}
	return globalCardDictionary.GetCard( index );
}

//----------------------------------------------------------------

int		Global::FindCardInDictionary( int cost, int damage, int heal, int numToDraw, int manaEarned )
{
	return	globalCardDictionary.FindCard( cost, damage, heal, numToDraw, manaEarned );
}

//----------------------------------------------------------------
//----------------------------------------------------------------

