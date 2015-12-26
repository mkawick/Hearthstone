========================================================================
    CONSOLE APPLICATION : Hearthstone Project Overview
========================================================================

This application is made to be easily extinsible with new cards, new behaviors, etc. I used a 
Data-driven model like many other card games on which I have worked. 

I took only a few short cuts. I wanted to focus of building the most easily extinsible 
model that I could in the  limited time that I had.

You may wonder why I went this route instead of using inheritance. I worked on Agricola, Ascension, and 
quite a few other card games and having a purely data driven model is more flexible and forces
The AI to look at the merits of the cards rather than on particular cards. Plus, you can always 
inherit for special cases.
Since you mentioned thinking about the design for the future in the design doc...

It also means that the AI can be written in a way that doesn't look for specific cards 
but looks for potential advantages based on card results as you apply a GA to it. 
In any case, I could easily have used an inheritance model, but if I am really thinking for the long-term
then a paramaterized model is a little better. This is especially true since none of the cards were truly
oddly behaved, although I was tempted with the legendary card, parameters were simply all
that was needed.

I have added comments for each design doc element. You should be able to see how each rule
is validatd. The overall design is pretty simple. I didn't bother with "attract" mode
or a menuing system since this was not called for. All tests were moved into 
Testing .cpp and many global functions and objects were moved into Global.cpp.

The overall design is a hybrid, mostly taking advantage of C++ and encapsulation
but avoid inheritance because it adds little in a purely data driven model. 
(it pains me to say that being such such an OOD/OOP guy). 

Currently, the text is not colored which would help tremendouosly and the output and code 
are mixed together. Both of these would be great, but there simply is not enough time.

If I had had more time, I would have added a game state object to manage control input and 
allow some sort of menuing and flow control. Then I could have avoided the use of globals
and global functions and put those into the game state model.

Another design shortcut I took was allowing direct access to the Player's hand and deck.
you shouldn't allow direct access from externally, but I broke encapsulation to speed delivery
given my time constraints.

I spent a fair amount of time testing and refining. This is hardly perfect and needs
a little love, but you should be able to gather a general sense of my overall C++ chops.

Workflow:
Build, run, test, write more tests, build the main parts over time. Putting together the final
Game was easy once I had all of the infrastructure in place.
I commited to git fairly often.
I also believe in taking breaks often so I would code for 30 minutes and then go away for several hours...
partially because this is Christmas time.
