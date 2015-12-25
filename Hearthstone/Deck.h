#pragma once

#include <vector>
#include "Card.h"

typedef std::vector <int> CardList;

class Deck
{
public:
	Deck();
	~Deck();

	void	AddCard( int indexInDictionary ); 
	void	Clear() { m_cards.clear(); }

	int		GetNumCards() const { return m_cards.size(); }
	int		GetCard( unsigned int index ) const;// each card indexes the global dictionary

	// utils .. not part of the normal functionality
	void	RemoveCard( unsigned int index );
	void	PrepBasicDeck();

	// testing
	const CardList & GetCardList() const { return m_cards; }
private:
	CardList m_cards;
};
