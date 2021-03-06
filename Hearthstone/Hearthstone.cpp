// Hearthstone.cpp : Defines the entry point for the console application.
//

#include "Deck.h"
#include "Player.h"
#include "Global.h"
#include <assert.h>
#include <random>
#include <algorithm>    // std::random_shuffle
#include <iostream>
#include <sstream>
using namespace std;
#pragma warning( disable:4996)

//----------------------------------------------------------------

bool	PrintEndOfGameState( const Player& player1, const Player& player2 )
{
	bool gameOver = false;
	if ( player1.IsDead() == true )
	{
		cout << "*****************************" << endl;
		cout << "Player " << player1.GetName() << " is dead" << endl;
		cout << "*****************************" << endl;
		gameOver = true;
	}
	if ( player2.IsDead() == true )
	{
		cout << "*****************************" << endl;
		cout << "Player " << player2.GetName() << " is dead" << endl;
		cout << "*****************************" << endl;
		gameOver = true;
	}
	return gameOver;
}

//----------------------------------------------------------------

void	PrintEndOfTurnMessage()
{
	cout << "*************************************" << endl;
	cout << "Play passes to opponent" << endl;
	cout << "Please change to opponent" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

//----------------------------------------------------------------

bool	DoesPlayerHaveEnoughManaToContinue( const Player& player )
{
	if ( player.HasEnoughManaToPlay() == false )
	{
		cout << endl;
		cout << "*************************************" << endl;
		cout << "ERROR: player does not have enough mana to play" << endl;
		cout << "*************************************" << endl;
		PrintEndOfTurnMessage();
		return false;
	}
	return true;
}

//----------------------------------------------------------------

void ApplyDamageIfPlayerIsOutOfCards( Player& player )
{
	int totalNumCards = player.GetDeck().GetNumCards();
	if ( totalNumCards == 0 )
	{
		cout << "*************************************" << endl;
		cout << "ERROR: player is out of cards" << endl;
		cout << "*************************************" << endl;
		player.ApplyDamage( 1 ); // design doc #9
	}
}

//----------------------------------------------------------------

int	HandleUserOption( const string& mystr, int numOptions)
{
	int choice;
	stringstream( mystr ) >> choice;
	if ( choice < 0 || choice >= numOptions )
	{
		cout << "*************************************" << endl;
		cout << "ERROR: bad input choice .. try again" << endl;
		cout << "*************************************" << endl;
		return -1;
	}
	return choice;
}

//----------------------------------------------------------------

bool	PlayCard( Player& attacker, Player& defender, int choice )
{
	Deck& attackerDeck = attacker.GetHand();
	auto card = Global::GetCardFromDictionary( attackerDeck.GetCard( choice ) );
	cout << "---> card choice was:" << card.GetName() << endl;

	if ( card.GetCost() <= attacker.GetMana() )
	{
		attacker.PlayCard( choice, defender );
		return true;
	}
	else
	{
		cout << "*************************************" << endl;
		cout << "ERROR: not enough mana to play that card" << endl;
		cout << "*************************************" << endl;
		return false;
	}
}

//----------------------------------------------------------------

void	PlayTurn( Player& attacker, Player& defender, const Deck& deck )
{
	cout << "Attacker: " << attacker.GetName() << endl;
	cout << "Defender: " << defender.GetName() << endl;

	cout << attacker.GetName() << " receives more mana " << endl;
	attacker.SetupForNextTurn( 1 ); // design doc #8
	cout << attacker.GetName() << " draws a new card. Card is:" << endl;
	ApplyDamageIfPlayerIsOutOfCards( attacker );
	attacker.DrawCard( true );

	while ( attacker.IsDead() == false && defender.IsDead() == false )
	{	
		if ( DoesPlayerHaveEnoughManaToContinue( attacker ) == false )
			break;

		defender.PrintAsOpponentState();	
		cout << "Current player is:" << endl;
		int numOptions = attacker.PrintState();

		cout << endl;
		cout << attacker.GetName() << " should enter a number to play a card 'p' to pass:" << endl;

		string mystr;
		getline( cin, mystr );
		if ( mystr == "" )
			continue;
		if ( mystr == "p" || mystr == "P" )
		{
			PrintEndOfTurnMessage();
			break;
		}

		int choice = HandleUserOption( mystr, numOptions );
		if ( choice == -1 )
			continue;
		
		PlayCard( attacker, defender, choice );
	}
	
	Global::WaitForUser();
	cout << "====================================" << endl;
	cout << "            player switch" << endl;
	cout << "====================================" << endl;
}

//----------------------------------------------------------------

void	PlayGame( Player& player1, Player& player2, const Deck& sourceDeckOfCards )
{
	player1.SetupForNewGame();
	player2.SetupForNewGame();

	Global::InitialzeDeckRandomly( player1, sourceDeckOfCards );
	Global::InitialzeDeckRandomly( player2, sourceDeckOfCards );

	player1.PickNewHand();
	player2.PickNewHand();

	//player2.DeductHealth( 27 );

	cout << "Beginning new game" << endl;
	cout << "----------------------" << endl;

	while ( PrintEndOfGameState( player1, player2 ) == false )
	{
		PlayTurn( player1, player2, sourceDeckOfCards );
		if ( PrintEndOfGameState( player1, player2 ) == true )
			break;

		PlayTurn( player2, player1, sourceDeckOfCards );
	}
}

//----------------------------------------------------------------

/*
The idea is that there is a global deck which is the dictionary or definition of all 
available cards. Then we select the proper number of each cards and store those. 
Then, each player gets a copy and shuffles it. This may be a bit of over-engineering
but I prefer this as it then can be used to initialize AI, many more players, and is 
more lightweight than calling PrepBasicDeck everytime which is fairly costly.

This allows us to initialize the data once and reuse it across multiple game instances 
saving memory and initialization. Otherwise, guaranteeing the right number of 
cards is not centralized and leads to more computationally costly code.
*/

int main( int argc, const char* argv[] )
{
	Deck sourceDeckOfCards;
	Player player1( "player1" ), player2( "player2" );

	Global::PrepGlobalDeck();// basically loading all cards into memory
	sourceDeckOfCards.PrepBasicDeck();	// now setup by proper counts and values.. design doc #2

#ifdef TESTING
	WaitForUser();
	InitialzeDeckRandomly( player1, deck ); 
	InitialzeDeckRandomly( player2, deck );
	ApplySimpleCardTest(player1, player2, deck);

	player1.PrintState();

	ApplySimpleCardTest2( player1, player2, deck );
	WaitForUser();
#endif
	
	PlayGame( player1, player2, sourceDeckOfCards ); // we could put a menuing system here to allow a restart, historical tracking, etc

	cout << endl;
	cout << "*******************************" << endl;
	cout << "        Game is ended" << endl;
	cout << "*******************************" << endl;

	Global::WaitForUser();

	return 0;
}

