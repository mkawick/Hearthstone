#pragma once

#include <vector>
#include "Card.h"

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
private:
	std::vector <Card> m_cards;
};
