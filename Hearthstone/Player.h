#pragma once

#include "Deck.h"

const int maximumPlayerMana = 10;
const int maximumPlayerHealth = 30;
const int numCardsInBeginningHand = 4;

class Player
{
public:
	Player( const char* name );
	~Player();

	bool	IsDead() const { if (m_health == 0) return true; return false; }
	int		GetHealth() const { return m_health; }
	int		GetMana() const { return m_mana; }

	void	SetupForNewGame();
	void	PickNewHand();
	void	DrawCard( bool displayCardStats );
	bool	PlayCard( unsigned int index, Player& opponent );
	bool	ApplyDamage( int damage );
	bool	ApplyHealing( int healing );
	
	const std::string& GetName() const { return m_name; }
	Deck&	Getdeck() { return m_deck; } // work directly on the data allows different algorithms to modify the data easily
	Deck&	Gethand( ) { return m_hand; }

	void	TurnSetup( int newMana = 1 );

	// the following are for logging and debug only
	void	PrintState() const;
	void	PrintAsOpponentState() const;
	void	PrintHand( bool includeIndices ) const;
	void	ApplyCard( const Card& card, Player& opponent );

private:
	std::string m_name;
	Deck		m_deck;
	Deck		m_hand;
	int			m_health;
	int			m_mana;
	bool		m_isDead;
	//Deck		m_discardDeck;// this should be part of any card game, but it is not part of this current design

	
};
