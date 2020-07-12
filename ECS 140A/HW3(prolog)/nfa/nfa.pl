reachable(StartState, FinalState, [H|T]) :-
  length([H|T],1),transition(StartState,H,StateList), member(FinalState,StateList).

reachable(StartState, FinalState, [H|T]) :-
  transition(StartState,H,StateList), member(S,StateList), reachable(S,FinalState,T).