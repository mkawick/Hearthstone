class Player;
class Deck;

void	ApplySimpleCardTest( Player& attacker, Player& defender, const Deck& deck );

void	Print( const Deck& deck );
void	RandomizeWithIndices( std::vector <int>& indices, int num );
void	InitialzeDeckRandomly( Player& deckReceiver, const Deck& availableDeck );
void	InitialzeDeckInOrder( Player& deckReceiver, const Deck& availableDeck );

int		FindCard( const Deck& deck, int damage, int heal, int numToDraw, int manaEarned );
void	WaitForUser();