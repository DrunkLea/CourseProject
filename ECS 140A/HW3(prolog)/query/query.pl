year_1953_1996_novels(Book) :-
    novel(Book,1953); novel(Book,1996).

period_1800_1900_novels(Book) :-
   novel(Book,X), X>=1800, X=<1900.

lotr_fans(Fan) :-
    fan(Fan,L),member(the_lord_of_the_rings,L).

author_names(Author) :-
   author(Author,BL),fan(chandler,FL),member(B,FL),member(B,BL).

fans_names(Fan) :-
    fan(Fan,FL),author(brandon_sanderson,BL),member(B,FL),member(B,BL).

mutual_novels(Book) :-
    fan(phoebe,P),fan(ross,R),member(Book,P),member(Book,R);
    fan(phoebe,P),fan(monica,M),member(Book,P),member(Book,M);
    fan(ross,R),fan(monica,M),member(Book,R),member(Book,M).
