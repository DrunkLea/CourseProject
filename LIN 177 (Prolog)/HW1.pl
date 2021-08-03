
cons(p).
cons(t).
cons(k).

vow(i).
vow(A):- name(A,[230]).
vow(u).
vow(A):- name(A,[593]).

onset(A):- cons(A).
nucleus(A):- vow(A).
syllable([O,N]):- onset(O),nucleus(N).
