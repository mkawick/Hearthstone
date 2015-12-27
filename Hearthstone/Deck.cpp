#include "Deck.h"
#include "Global.h"
#include <assert.h>
#include <iostream>
using namespace std;

//----------------------------------------------------------------

Deck::Deck()
{
}

//----------------------------------------------------------------

/*
Deck::~Deck()
{
}*/

//----------------------------------------------------------------

void	Deck::AddCard( int indexInDictionary )
{
	m_cards.push_back( indexInDictionary );
}

//----------------------------------------------------------------

int		Deck::GetCard( unsigned int index ) const
{
	assert( index < m_cards.size() );
	if ( index >= m_cards.size() )
	{
		cout << "ERROR: Bad card index. " << endl;
		return m_cards[0];
	}
	return m_cards[index];
}

//----------------------------------------------------------------

void	Deck::RemoveCard( unsigned int index )
{
	assert( index < m_cards.size() );
	if ( index >= m_cards.size() )
	{
		cout << "ERROR: Bad card index. " << endl;
		return;
	}

	m_cards.erase( m_cards.begin() + index );
}

//----------------------------------------------------------------

void	Deck::PrepBasicDeck()  // design doc #2
{
	assert( Global::IsGlobalDeckLoaded() == true );

	// this configuration should be read in from a file or other means.
	// I didn't give this much thought because the design was unclear as to the
	// particular needs. Maybe passing in a config file is best.

	// using auto here makes it much easier to migrate to using other types like Card
	// in the future. Just future-proofing. They are simple ints right now.

	// also, the code 
	auto card_a = Global::FindCardInDictionary( 1, 1, 0, 0, 0 );
	if ( card_a != Global::invalidCard )
	{
		for ( int i = 0; i < 10; ++i ) // design doc #2
		{
			AddCard( card_a );
		}
	}

	auto  card_b = Global::FindCardInDictionary( 2, 2, 0, 0, 0 );
	if ( card_b != Global::invalidCard )
	{
		for ( int i = 0; i < 4; ++i ) // design doc #2
		{
			AddCard( card_b );
		}
	}

	auto card_c = Global::FindCardInDictionary( 3, 3, 0, 0, 0 );
	if ( card_c != Global::invalidCard )
	{
		for ( int i = 0; i < 2; ++i ) // design doc #2
		{
			AddCard( card_c );
		}
	}

	auto card_d = Global::FindCardInDictionary( 4, 4, 0, 0, 0 );
	if ( card_d != Global::invalidCard )
	{
		for ( int i = 0; i < 2; ++i ) // design doc #2
		{
			AddCard( card_d );
		}
	}

	auto card_e = Global::FindCardInDictionary( 5, 5, 0, 0, 0 );
	if ( card_e != Global::invalidCard )
	{
		for ( int i = 0; i < 2; ++i ) // design doc #2
		{
			AddCard( card_e );
		}
	}

	auto card_f = Global::FindCardInDictionary( 1, 0, 1, 0, 0 );
	if ( card_f != Global::invalidCard )
	{
		for ( int i = 0; i < 5; ++i )
		{
			AddCard( card_f );
		}
	}

	auto card_g = Global::FindCardInDictionary( 2, 0, 2, 0, 0 );
	if ( card_g != Global::invalidCard )
	{
		for ( int i = 0; i < 2; ++i )
		{
			AddCard( card_g );
		}
	}

	auto card_h = Global::FindCardInDictionary( 1, 1, 0, 1, 0 );
	if ( card_h != Global::invalidCard )
	{
		for ( int i = 0; i < 2; ++i )
		{
			AddCard( card_h );
		}
	}

	auto card_i = Global::FindCardInDictionary( 5, 4, 0, 0, 1 );
	if ( card_i != Global::invalidCard )
	{
		AddCard( card_i );
	}
}

//----------------------------------------------------------------
//----------------------------------------------------------------
