#pragma once

#include "Deck.h"
#include "Global.h"

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
	Deck&	GetDeck() { return m_deck; } // work directly on the data allows different algorithms to modify the data easily
	Deck&	GetHand( ) { return m_hand; }

	void	TurnSetup( int newMana = 1 );
	bool	HasEnoughManaToPlay() const;

	// the following are for logging and debug only
	int		PrintState() const;
	void	PrintAsOpponentState() const;
	int		PrintHand( bool includeIndices ) const;
	void	ApplyCard( const Card& card, Player& opponent );

#if defined (_DEBUG)
	void	GiveMana( int amount ) { m_mana += amount; }
#endif

private:
	std::string m_name;
	Deck		m_deck; // design doc #3
	Deck		m_hand;
	int			m_health;
	int			m_mana;
	bool		m_isDead;
	//Deck		m_discardDeck;// this should be part of any card game, but it is not part of this current design

	
};
