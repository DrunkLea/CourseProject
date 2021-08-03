:- ['properties.pl'].
:- ['entailment.pl'].

cspanish([momen,t],[noun,stem]).
cspanish([po,k],[noun,stem]).

cspanish([P], [suffix, masculine]) :-
phone(P), not(cns(P)), bck(P), mid(P).

cspanish([i,P], [suffix, diminutive]) :-
phone(P),not(lab(P)),not(voi(P)),not(cnt(P)),not(pal(P)).

cspanish(MasculineNoun,[noun,masculine]):-
cspanish(Stem,[noun,stem]),
cspanish(MascullineSuffix,[suffix, masculine]),
append(Stem,MascullineSuffix,MasculineNoun).

cspanish(DiminutiveStem,[noun,stem]):-
cspanish(X,[noun,stem]),
cspanish(DS,[suffix, diminutive]),
append(X,DS,DiminutiveStem),
last(X,Xlast),last(DS,DSlast),
not(homorganic(Xlast,DSlast)).

homorganic(A,B):- vel(A) <=> vel(B).
