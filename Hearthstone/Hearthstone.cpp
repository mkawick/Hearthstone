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

bool	PrintEndOfGameState( const Player& player1, const Player& player2 )
{
	bool gameOver = false;
	if ( player1.IsDead( ) == true )
	{
		cout << "*****************************" << endl;
		cout << "Player " << player1.GetName( ) << " is dead" << endl;
		cout << "*****************************" << endl;
		gameOver = true;
	}
	if ( player2.IsDead( ) == true )
	{
		cout << "*****************************" << endl;
		cout << "Player " << player2.GetName( ) << " is dead" << endl;
		cout << "*****************************" << endl;
		gameOver = true;
	}
	return gameOver;
}

void	PrintEndOfTurnMessage()
{
	cout << "Play passes to opponent" << endl;
	cout << endl;
}

void	PlayTurn( Player& attacker, Player& defender, const Deck& deck )
{
	cout << "Attacker: " << attacker.GetName( ) << endl;
	cout << "Defender: " << defender.GetName( ) << endl;

	cout << attacker.GetName( ) << " receives more mana " << endl;
	attacker.TurnSetup( 1 ); // design doc #8
	cout << attacker.GetName( ) << " draws a new card. Card is:" << endl;
	attacker.DrawCard( true );

	while ( attacker.IsDead( ) == false && defender.IsDead() == false )
	{	
		if ( attacker.HasEnoughManaToPlay() == 0 )
		{
			cout << endl;
			cout << "ERROR: player does not have enough mana to play" << endl;
			PrintEndOfTurnMessage();
			break;
		}
		//cout << "Attacker: " << attacker.GetName( ) << endl;
		//cout << "Defender: " << defender.GetName( ) << endl;

		defender.PrintAsOpponentState( );	
		int numOptions = attacker.PrintState( );
		int totalNumCards = attacker.GetDeck().GetNumCards();
		if ( totalNumCards == 0 )
		{
			cout << "ERROR: player is out of cards" << endl;
			attacker.ApplyDamage( 1 ); // design doc #9
		}


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

		int choice;

		stringstream( mystr ) >> choice;

		if ( choice < 0 || choice >= numOptions )
		{
			cout << "ERROR: bad input choice .. try again" << endl;
			continue;
		}
		

		Deck& attackerDeck = attacker.GetHand( );
		auto card = GetCardFromDictionary( attackerDeck.GetCard( choice ) );

		cout << "choice was " << card.GetName() << endl;

		if ( card.GetCost( ) <= attacker.GetMana( ) )
		{
			attacker.PlayCard( choice, defender );
		}
		else
		{
			cout << "ERROR: not enough mana" << endl;
		}
	}
	
	WaitForUser( );
	cout << "====================================" << endl;
	cout << "            player switch" << endl;
	cout << "====================================" << endl;
}



void	PlayGame( Player& player1, Player& player2, const Deck& deck )
{
	player1.SetupForNewGame( );
	player2.SetupForNewGame( );
	InitialzeDeckRandomly( player1, deck );
	InitialzeDeckRandomly( player2, deck );
	player1.PickNewHand( );
	player2.PickNewHand( );

	cout << "Beginning new game" << endl;
	cout << "----------------------" << endl;

	while ( PrintEndOfGameState( player1, player2 ) == false )
	{
		PlayTurn( player1, player2, deck );
		if ( PrintEndOfGameState( player1, player2 ) == true )
			break;

		PlayTurn( player2, player1, deck );
	}
}


int main( int argc, const char* argv[] )
{
	Deck deck;
	Player player1( "player1" ), player2( "player2" );
	PrepGlobalDeck( );// basically loading all cards into memory

	deck.PrepBasicDeck();
	

#ifdef TESTING
	WaitForUser();
	InitialzeDeckRandomly( player1, deck ); 
	InitialzeDeckRandomly( player2, deck );
	ApplySimpleCardTest(player1, player2, deck);

	player1.PrintState( );

	ApplySimpleCardTest2( player1, player2, deck );
	WaitForUser( );
#endif
	
	PlayGame( player1, player2, deck ); // we could put a menuing system here to allow a restart, historical tracking, etc

	WaitForUser( );

	return 0;
}

