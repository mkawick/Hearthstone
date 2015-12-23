#include "Card.h"

#include <iostream>
using namespace std;

Card::Card( int manaCost, int damage, int heal, int cardsDrawn, int manaEarned, const char* name ) :
	m_manaCost( manaCost ),
	m_damage( damage ),
	m_heal( heal ),
	m_numCardsToDraw( cardsDrawn ),
	m_manaEarned( manaEarned ),
	m_name( name )	
{
}

Card::~Card()
{
}

void	Card::PrintStats( int index ) const
{
	cout << "------------------------------" << endl;
	if (index != -1)
	{
		cout << index << ") ";
	}
	cout << "Card name: " << m_name << endl;
	cout << "------------------------------" << endl;
	cout << "    manaCost: " << m_manaCost << endl;
	cout << "      damage: " << m_damage << endl;
	cout << "        heal: " << m_heal << endl;
	cout << "  cardsDrawn: " << m_numCardsToDraw << endl;
	cout << "  manaEarned: " << m_manaEarned << endl;
	cout << endl;
}

void	Card::PrintSimpleStats( int index ) const
{
	
	if (index != -1)
	{
		cout << index << ") ";
	}
	cout << "Card name: " << m_name << endl;
	if (m_manaCost)
	{
		cout << "    manaCost: " << m_manaCost << endl;
	}
	if (m_damage)
	{
		cout << "      damage: " << m_damage << endl;
	}
	if (m_heal)
	{
		cout << "        heal: " << m_heal << endl;
	}
	if (m_numCardsToDraw)
	{
		cout << "  cardsDrawn: " << m_numCardsToDraw << endl;
	}
	if (m_manaEarned)
	{
		cout << "  manaEarned: " << m_manaEarned << endl;
	}
	cout << endl;
}