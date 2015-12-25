class Player;
class Deck;
class CardDictionary;


extern const int maximumPlayerMana; // design doc #1
extern const int maximumPlayerHealth;  // design doc #4
extern const int numCardsInBeginningHand; // design doc #4

void	ApplySimpleCardTest( Player& attacker, Player& defender, const Deck& deck );
void	ApplySimpleCardTest2( Player& attacker, Player& defender, const Deck& deck );

void	Print( const Deck& deck );
void	RandomizeWithIndices( std::vector <int>& indices, int num );
void	InitialzeDeckRandomly( Player& deckReceiver, const Deck& availableDeck );
void	InitialzeDeckInOrder( Player& deckReceiver, const Deck& availableDeck );


void	WaitForUser();

bool	IsGlobalDeckLoaded();
void	PrepGlobalDeck();
int		GetDictionarySize();
const Card& GetCardFromDictionary( int index );
int		FindCardInDictionary( int cost, int damage, int heal, int numToDraw, int manaEarned );