========================================================================
    CONSOLE APPLICATION : Hearthstone Project Overview
========================================================================

// This application is made to be easily extinsible with new cards, new behaviors, etc. I used a 
// Data-driven model like many other card games on which I have worked. 

// I took only a few short cuts like not using pointers but using pass-by-value
// which is costlier than passing pointers, but the objects are small and 
// memory mgmt would take more effort than the time I was given. I wanted to 
// focus of building the most easily extinsible model that I could in the 
// limited time that I had.

// you may wonder why I went this route. I worked on Agricola, Ascension, and 
// quite a few other card games and having a purely data driven model is much more flexible.
// Since you mentioned thinking about the design for the future in the design doc...

// It also means that the AI can be written in a way that doesn't look for specific cards 
// but looks for potential advantages as you apply a GA to it. In any case, I could easily
// have used an inheritance model, but if I am really thinking for the long-term
// then a paramaterized model is much better.