#pragma once 

class Player;
class Deck;
class CardDictionary;

namespace Global
{
	static const int playerBeginningMana = 1;		// design doc #1
	static const int maximumPlayerMana = 10;			// design doc #1
	static const int maximumPlayerHealth = 30;		// design doc #4
	static const int numCardsInBeginningHand = 4;	// design doc #4
	static const int invalidCard = -1;


	void	ApplySimpleCardTest( Player& attacker, Player& defender, const Deck& deck );
	void	ApplySimpleCardTest2( Player& attacker, Player& defender, const Deck& deck );

	void	Print( const Deck& deck );
	void	RandomizeWithIndices( std::vector <int>& indices, int num );
	void	InitialzeDeckRandomly( Player& deckReceiver, const Deck& availableDeck );
	void	InitialzeDeckInOrder( Player& deckReceiver, const Deck& availableDeck );
	int		ChooseRandomNumber( int rangeMin, int rangeMax );


	void	WaitForUser();

	bool	IsGlobalDeckLoaded();
	void	PrepGlobalDeck();
	int		GetDictionarySize();
	const Card& GetCardFromDictionary( int index );
	int		FindCardInDictionary( int cost, int damage, int heal, int numToDraw, int manaEarned );
}