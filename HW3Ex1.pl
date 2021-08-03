dutch([been], [noun,singular]).
dutch([berg], [noun,singular]).
dutch([steen], [noun,singular]).
dutch([dier], [noun,singular]).

dutch([ge],[circumfix,head]).
dutch([te],[circumfix,tail]).

dutch(PluralNoun,[noun,plural]):-
dutch(SingularNoun,[noun,singular]),
dutch(H,[circumfix,head]),dutch(T,[circumfix,tail]),
append(H,SingularNoun,X),append(X,T,PluralNoun).