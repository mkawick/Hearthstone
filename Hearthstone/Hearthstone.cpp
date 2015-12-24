// Hearthstone.cpp : Defines the entry point for the console application.
//

#include "Deck.h"
#include "Player.h"
#include "Global.h"
#include <assert.h>
#include <random>
#include <algorithm>    // std::random_shuffle
#include <iostream>
using namespace std;
#pragma warning( disable:4996)





//void	P



int main( int argc, const char* argv[] )
{
	Deck deck;
	Player player1( "player1" ), player2( "player2" );

	deck.PrepStaticDeck();
	InitialzeDeckRandomly( player1, deck ); 
	InitialzeDeckRandomly( player2, deck );
	WaitForUser();

	ApplySimpleCardTest(player1, player2, deck);

	player1.PrintState( );

	player1.SetupForNewGame( );
	player2.PrintState( );
	player2.SetupForNewGame( );

	InitialzeDeckInOrder( player1, deck );
	InitialzeDeckInOrder( player2, deck );
	
	int cardIndex = FindCard( deck, 4, 0, 0, 1 );
	player1.GiveMana( 8 );
	player1.ApplyCard( deck.GetCard( cardIndex ), player2 );
	WaitForUser();

	//Print(deck);
	//Print( player1.Getdeck() );
	//Print( player2.Getdeck() );

	return 0;
}

