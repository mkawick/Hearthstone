#include "Deck.h"
#include <assert.h>
#include <iostream>
using namespace std;

Deck::Deck()
{
}

Deck::~Deck()
{
}

void	Deck::AddCard(  const Card& card )
{
	m_cards.push_back(card);
}

void	Deck::PrintDeck()
{
}


const Card& Deck::GetCard( unsigned int index ) const
{
	assert(index < m_cards.size());
	if (index >= m_cards.size())
	{
		cout << "ERROR: Bad card index. " << endl;
		return m_cards[0];
	}
	return m_cards[index];
}

void	Deck::RemoveCard(int index)
{
	if (index < m_cards.size())
	{
		m_cards.erase(m_cards.begin() + index);
	}
}

void	Deck::PrepStaticDeck()
{
	Card card_a(1, 1, 0, 0, 0, "deal 1 damage and cost 1 mana");
	for (int i = 0; i<10; i++)
	{
		AddCard(card_a);
	}

	Card card_b(2, 2, 0, 0, 0, "deal 2 damage and cost 2 mana");
	for (int i = 0; i<4; i++)
	{
		AddCard(card_b);
	}

	Card card_c(3, 3, 0, 0, 0, "deal 3 damage and cost 3 mana");
	for (int i = 0; i<2; i++)
	{
		AddCard(card_c);
	}

	Card card_d(4, 4, 0, 0, 0, "deal 4 damage and cost 4 mana");
	for (int i = 0; i<2; i++)
	{
		AddCard(card_d);
	}

	Card card_e(5, 5, 0, 0, 0, "deal 5 damage and cost 5 mana");
	for (int i = 0; i<2; i++)
	{
		AddCard(card_e);
	}

	Card card_f(1, 0, 1, 0, 0, "heal 1 damage and cost 1 mana");
	for (int i = 0; i<5; i++)
	{
		AddCard(card_f);
	}

	Card card_g(2, 0, 2, 0, 0, "heal 2 damage and cost 2 mana");
	for (int i = 0; i<2; i++)
	{
		AddCard(card_g);
	}

	Card card_h(1, 1, 0, 1, 0, "deal 1 damage, cost 1 mana, draw 1 card");
	for (int i = 0; i<2; i++)
	{
		AddCard(card_h);
	}

	Card card_i(5, 4, 0, 0, 1, "deal 4 damage, cost 5 mana, return 1 mana, output message");
	AddCard(card_i);
}