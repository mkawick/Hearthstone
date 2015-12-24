#pragma once

#include <vector>
#include "Card.h"

typedef std::vector <Card> CardList;
class Deck
{
public:
	Deck();
	~Deck();

	void	AddCard( const Card& card ); 
	void	Clear() { m_cards.clear(); }
	void	PrintDeck();

	int		GetNumCards() const { return m_cards.size(); }
	const Card& GetCard( unsigned int index ) const;
//	Deck	Randomi

	// utils
	void	RemoveCard( int index );
	void	PrepStaticDeck();

	// testing
	const CardList & GetCardList() const { return m_cards; }
private:
	CardList m_cards;
};
