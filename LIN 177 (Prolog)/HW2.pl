language(arabic).
language(nahuatl).
language(urdu).
language(tlingit).
language(hawaiian).
language(english).
language(french).

% quadrilingual 
speaks(jane, arabic).
speaks(jane, nahuatl).
speaks(jane, urdu).
speaks(jane, tlingit).

speaks(whitney,arabic).
speaks(whitney,urdu).
speaks(whitney,english).
speaks(whitney,french).

speaks(sally,french).
speaks(sally,tlingit).
speaks(sally,urdu).
speaks(sally,hawaiian).

% non-quadrilingual
speaks(frank, hawaiian).
speaks(frank, english).
speaks(george,english).
speaks(george,arabic).
speaks(bob,english).


quadrilingual(X):- language(A),language(B),language(C),language(D),
speaks(X,A),speaks(X,B),speaks(X,C),speaks(X,D).
