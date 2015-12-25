#include "Deck.h"
#include "Global.h"
#include <assert.h>
#include <iostream>
using namespace std;

Deck::Deck()
{
}
/*
Deck::~Deck()
{
}*/

void	Deck::AddCard( int indexInDictionary )
{
	m_cards.push_back( indexInDictionary );
}

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

void	Deck::PrepBasicDeck()  // design doc #2
{
	assert( IsGlobalDeckLoaded() == true );

	auto card_a = FindCardInDictionary( 1, 1, 0, 0, 0 );
	for (int i = 0; i<10; ++i)
	{
		AddCard(card_a);
	}

	auto  card_b = FindCardInDictionary( 2, 2, 0, 0, 0 );
	for (int i = 0; i<4; ++i)
	{
		AddCard(card_b);
	}

	auto card_c = FindCardInDictionary( 3, 3, 0, 0, 0 );
	for (int i = 0; i<2; ++i)
	{
		AddCard(card_c);
	}

	auto card_d = FindCardInDictionary( 4, 4, 0, 0, 0 );
	for (int i = 0; i<2; ++i)
	{
		AddCard(card_d);
	}

	auto card_e = FindCardInDictionary( 5, 5, 0, 0, 0 );
	for (int i = 0; i<2; ++i)
	{
		AddCard(card_e);
	}

	auto card_f = FindCardInDictionary( 1, 0, 1, 0, 0 );
	for (int i = 0; i<5; ++i)
	{
		AddCard(card_f);
	}

	auto card_g = FindCardInDictionary( 2, 0, 2, 0, 0 );
	for (int i = 0; i<2; ++i)
	{
		AddCard(card_g);
	}

	auto card_h = FindCardInDictionary( 1, 1, 0, 1, 0 );
	for (int i = 0; i<2; ++i)
	{
		AddCard(card_h);
	}

	auto card_i = FindCardInDictionary( 5, 4, 0, 0, 1 );
	AddCard(card_i);
}