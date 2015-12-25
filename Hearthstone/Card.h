#pragma once

// I also decided that this would probably be initialized through static data or from an 
// excel sheet so this constructor model works.. we could certainly have done the same 
// through normal accessors
class Player;
#include <string>
#include <vector>

class Card
{
public:
	Card( int manaCost, int damage, int heal, int cardsDrawn, int manaEarned, const char* name );
	~Card();

	std::string GetName() const { return m_name; }
	int 		GetCost() const { return m_manaCost; }
	int 		GetDamage() const { return m_damage; }
	int 		GetHealing() const { return m_heal; }
	int 		GetNumToDraw() const { return m_numCardsToDraw; }
	int 		GetManaEarned() const { return m_manaEarned; }
	const std::string& 	GetMessage() const { return m_message; }

	void		PrintStats( int index = -1 ) const;
	void		PrintSimpleStats( int index = -1 ) const;

	void		AddMessage( const std::string& message ) { m_message = message; }  // design doc #2

public:
	int 		m_manaCost;
	int 		m_damage;
	int 		m_heal; 
	int 		m_numCardsToDraw;
	int 		m_manaEarned;
	std::string m_name;
	std::string m_message;
};

class CardDictionary
{
public:// no c'tor needed 
	
	int			GetNumCards() const { return cardList.size(); }
	void		AddCard( const Card& card );
	// we will not remove cards from the dictionary

	const Card& GetCard( unsigned int index ) const;
	int			FindCard( int cost, int damage, int heal, int numToDraw, int manaEarned );

private:
	std::vector <Card> cardList;
};