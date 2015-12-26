#pragma once

// I also decided that this would probably be initialized through static data or from an 
// excel sheet so this constructor model works.. we could certainly have done the same 
// through normal accessors
class Player;
#pragma once

#include <string>
#include <vector>

class Card
{
public:
	// I went purely data driven instead of using inheritance. this was mainly because
	// setting up inheritance creates weird dependencies between AI and card types
	// and time constraints made me decide that this was the best approach.
	// ECS may be the best overall design, but I did not have enough time.

	Card( int manaCost, int damage, int heal, int cardsDrawn, int manaEarned, const char* name );
	// virtual ~Card();// default is fine but if someone needs to derive from this class

	int 		GetCost() const { return m_manaCost; }
	int 		GetDamage() const { return m_damage; }
	int 		GetHealing() const { return m_heal; }
	int 		GetNumToDraw() const { return m_numCardsToDraw; }
	int 		GetManaEarned() const { return m_manaEarned; }
	std::string GetName() const { return m_name; }
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

	// nice utility function
	int			FindCard( int cost, int damage, int heal, int numToDraw, int manaEarned );

private:
	std::vector <Card> cardList;
};