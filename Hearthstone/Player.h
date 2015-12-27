#pragma once

#include "Deck.h"
#include "Global.h"

// Each player has his own deck as seen here. These are randomly choosen from the global deck
// which is initialized before the palyers are created.

class Player
{
public:
	Player( const char* name );
	//~Player(); default d'tor is fine

	bool	IsDead() const { return m_isDead; }
	int		GetHealth() const { return m_health; }
	int		GetMana() const { return m_mana; }
	const std::string& GetName() const { return m_name; }
	Deck&	GetDeck() { return m_deck; } // work directly on the data allows different algorithms to modify the data easily
	Deck&	GetHand() { return m_hand; }

	void	SetupForNewGame();
	void	PickNewHand();
	void	DrawCard( bool displayCardStats );
	bool	PlayCard( unsigned int index, Player& opponent );
	bool	AddMana( int amount );
	bool	ApplyDamage( int damage );
	bool	ApplyHealing( int healing );

	void	SetupForNextTurn( int newMana = 1 );
	bool	HasEnoughManaToPlay() const;

	// the following are for logging and debug only
	int		PrintState() const;
	void	PrintAsOpponentState() const;
	int		PrintHand( bool includeIndices ) const;
	//void	ApplyCard( const Card& card, Player& opponent );
	void	DrawMultipleCards( int num );

#if defined (_DEBUG)
	void	GiveMana( int amount ) { m_mana += amount; }
	void	DeductHealth( int amount ) { m_health -= amount; }
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
