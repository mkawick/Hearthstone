#include "Player.h"

#include <assert.h>
#include <iostream>
using namespace std;

Player::Player( const char* name ) : 
	m_name( name ),
	m_health( maximumPlayerHealth ),
	m_isDead( false )
	
{
}

Player::~Player()
{
}

void	Player::SetupForNewGame()
{ 
	m_mana = 1;
	m_health = maximumPlayerHealth;
	m_hand.Clear();
	m_isDead = false;
}

void	Player::PickNewHand()
{
	int cardCount = numCardsInBeginningHand;
	if (cardCount > m_deck.GetNumCards())
	{
		cardCount = m_deck.GetNumCards();
	}
	for (int i = 0; i < cardCount; i++)
	{
		int numCards = m_deck.GetNumCards();
		int r = rand() % numCards;
		m_hand.AddCard( m_deck.GetCard( r ) );
		m_deck.RemoveCard( r );
	}
}

void	Player::DrawCard( bool displayCardStats )
{
	if (m_deck.GetNumCards() == 0) // design doc #9
	{
		cout << "Player takes damage for having no cards" << endl;
		m_health--;
		return;
	}

	auto c = m_deck.GetCard( 0 );
	if ( displayCardStats )
	{
		GetCardFromDictionary( c ).PrintSimpleStats( );
	}
	m_hand.AddCard( c );
	m_deck.RemoveCard(0); // design doc #5
}

bool	Player::PlayCard( unsigned int index, Player& opponent )
{
	auto card = m_hand.GetCard( index );
	
	ApplyCard( GetCardFromDictionary( card ), opponent );
	m_hand.RemoveCard( index );
	return true;
}

bool	Player::ApplyDamage( int damage )
{
	if ( m_isDead == false )
	{
		m_health -= damage;
		if ( m_health <= 0 )
		{
			m_health = 0;
			cout << "Player has died: " << m_name << endl;
			m_isDead = true;
		}
		return true;
	}
	return false;
}

bool	Player::ApplyHealing( int healing )
{
	if ( m_isDead == false )
	{
		m_health += healing;
		if ( m_health > maximumPlayerHealth )
		{
			m_health = maximumPlayerHealth;
			cout << "Player has full health: " << m_name << endl;
		}
		return true;
	}
	return false;
}

void	Player::TurnSetup( int newMana )
{
	m_mana += newMana;
	if (m_mana > maximumPlayerMana)
	{
		m_mana = maximumPlayerMana;
	}
	if (m_mana < 0)
	{
		m_mana = 0;
	}
}

bool	Player::HasEnoughManaToPlay( ) const
{
	int  numCards = m_hand.GetNumCards( );
	for ( int i = 0; i < numCards; i++ )
	{
		auto card = GetCardFromDictionary( m_hand.GetCard( i ) );
		if ( card.GetCost() <= m_mana )
			return true;
	}
	return false;
}

int		Player::PrintState() const
{
	cout << "--------- stats --------" << endl;
	cout << "       name: " << m_name << endl;
	cout << "  deck size: " << m_deck.GetNumCards() << endl;
	cout << "     health: " << m_health << endl;
	cout << "       mana: " << m_mana << endl;
	cout << "------------------------" << endl;
	int numOptions = PrintHand( true );
	cout << "------------------------" << endl;

	return numOptions;
}

void	Player::PrintAsOpponentState() const
{
	cout << "--------- stats --------" << endl;
	cout << "       name: " << m_name << endl;
	cout << "     health: " << m_health << endl;
	cout << "       mana: " << m_mana << endl;
	cout << "------------------------" << endl;
}

int		Player::PrintHand( bool includeIndices ) const
{
	cout << "          hand   " << endl;
	int  numCards = m_hand.GetNumCards();
	cout << "------------------------------" << endl;
	for (int i = 0; i < numCards; i++)
	{
		auto card = GetCardFromDictionary( m_hand.GetCard( i ) );
		int index = i;
		if (includeIndices == false)
		{
			index = -1;
		}
		card.PrintSimpleStats( index );
	}
	cout << "------------------------------" << endl;
	return numCards;
}

void	Player::ApplyCard( const Card& card, Player& opponent )
{
	if ( card.m_manaCost )
	{
		assert( card.m_manaCost <= m_mana );// should be checked before playing card
		m_mana -= card.m_manaCost;
	}
	if ( card.GetDamage( ) ) // as per #7 in design
	{
		cout << "Applying damage to " << opponent.GetName() << endl;
		opponent.ApplyDamage( card.GetDamage( ) );
	}
	if ( card.GetHealing( ) ) // as per #7 in design
	{
		cout << "Applying healing to " << GetName( ) << endl;
		ApplyHealing( card.GetHealing( ) );
	}
	if ( card.GetNumToDraw( ) )
	{
		int num = card.GetNumToDraw( );
		cout << "Drawing cards .. num: " << card.GetNumToDraw( ) << endl;
		for ( int i = 0; i < num; i++ )
		{
			DrawCard( true );
		}
	}
	if ( card.GetManaEarned( ) ) // as per #7 in design
	{
		m_mana += card.GetManaEarned( );
		cout << "Mana earned: " << card.GetManaEarned( ) << endl;
	}
	if ( card.GetMessage().length() )
	{
		cout << card.GetMessage( ) << endl;
	}
}
