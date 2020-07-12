isUnion([],[],[]).
isUnion(S,[],S).
isUnion([],S,S).
isUnion([H|T],S2,R) :- member(H,S2), isUnion(T,S2,R).
isUnion([H|T],S2,R) :-  not(member(H,S2)), isUnion(T,S2,RST),append([H],RST,R).

isIntersection([],[],[]).
isIntersection(S,[],[]).
isIntersection([],S,[]).
isIntersection([H|T],S2,R) :- member(H,S2), isIntersection(T,S2,RST),append([H],RST,R).
isIntersection([H|T],S2,R) :- not(member(H,S2)),isIntersection(T,S2,R).

isEqual([],[]).
isEqual([H|T],S2) :-
  length([H|T],Y),length(S2,Y),vst([H|T],S2).
vst([],S).
vst([H|T],S) :- member(H,S),vst(T,S).