#pragma once

// you may wonder why I went this route. I worked on Agricola, Ascension, and 
// quite a few other card games and having a purely data driven model is much more flexible.
// Since you mentioned thinking about the design for the future...

// It also means that the AI can be written in a way that doesn't look for specific cards 
// but looks for potential advantages as you apply a GA to it. In any case, I could easily
// have used an inheritance model, but if I am really thinking for the long-term
// then a paramaterized model is much better.

// I also decided that this would probably be initialized through static data or from an 
// excel sheet so this constructor model works.. we could certainly have done the same 
// through normal accessors
class Player;
#include <string>


class Card
{
public:
	Card( int manaCost, int damage, int heal, int cardsDrawn, int manaEarned, const char* name );
	~Card();

	int 	GetCost() const { return m_manaCost; }
	int 	GetDamage() const { return m_damage; }
	int 	GetHealing() const { return m_heal; }
	int 	GetHowManyToDraw() const { return m_numCardsToDraw; }
	int 	GetManaEarned() const { return m_manaEarned; }

	void	PrintStats( int index = -1 ) const;
	void	PrintSimpleStats( int index = -1 ) const;
	//virtual void	Play() {}

	void	PlayCard( Player& personPlayingCard, Player& opponent ) const;

public:
	int 		m_manaCost;
	int 		m_damage;
	int 		m_heal; 
	int 		m_numCardsToDraw;
	int 		m_manaEarned;
	std::string m_name;
};

/*
class Card_a
{
};*/