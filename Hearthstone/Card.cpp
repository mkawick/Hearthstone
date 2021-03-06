#include "Card.h"
#include "Global.h"
#include "Player.h"

#include <assert.h>
#include <iostream>
using namespace std;

//----------------------------------------------------------------

Card::Card( int manaCost, int damage, int heal, int cardsDrawn, int manaEarned, const char* name ) :
	m_manaCost( manaCost ),
	m_damage( damage ),
	m_heal( heal ),
	m_numCardsToDraw( cardsDrawn ),
	m_manaEarned( manaEarned ),
	m_name( name )	
{
}

/*
Card::~Card()
{
}
*/

//----------------------------------------------------------------

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

//----------------------------------------------------------------

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

//----------------------------------------------------------------
// I struggled with whether this should go in the player or in the card. Due to long-
// term extensibility issues, I chose this route.

void	Card::Play( Player& player, Player& opponent ) const
{
	if ( GetCost() )
	{
		assert( GetCost() <= player.GetMana() );// should be checked before playing card
		player.AddMana( - GetCost() ); // note negative sign
	}
	if ( GetDamage() ) // design doc #7
	{
		cout << "Applying damage to " << opponent.GetName() << endl;
		opponent.ApplyDamage( GetDamage() );
	}
	if ( GetHealing() ) // design doc #7
	{
		cout << "Applying healing to " << GetName() << endl;
		player.ApplyHealing( GetHealing() );
	}
	if ( GetNumToDraw() )
	{
		player.DrawMultipleCards( GetNumToDraw() );
	}
	if ( GetManaEarned() )
	{
		player.AddMana( GetManaEarned() );
		cout << "Mana earned: " << GetManaEarned() << endl;
	}
	if ( GetMessage().length() )
	{
		cout << GetMessage() << endl;
	}
}

//----------------------------------------------------------------
//----------------------------------------------------------------

void	CardDictionary::AddCard( const Card& card )
{
	cardList.push_back( card );
}

//----------------------------------------------------------------

const Card& CardDictionary::GetCard( unsigned int index ) const
{
	assert( index < cardList.size() );
	if ( index >= cardList.size() )
	{
		cout << "ERROR: Bad card index. " << endl;
		return cardList[0];
	}
	return cardList[index];
}

//----------------------------------------------------------------

int CardDictionary::FindCard( int cost, int damage, int heal, int numToDraw, int manaEarned )
{
	int num = cardList.size();
	//auto cardList = cardList.GetCardList();

	for ( int i = 0; i < num; ++i )// I played with lots of different iterator types here and this is best
	{
		const Card& card = cardList[i];
		if ( card.GetCost() == cost &&
			card.GetDamage() == damage &&
			card.GetHealing() == heal &&
			card.GetNumToDraw() == numToDraw &&
			card.GetManaEarned() == manaEarned )
		{
			return  i;
		}
	}

	return Global::invalidCard;
}

//----------------------------------------------------------------
