:- ['properties.pl'].
:- ['entailment.pl'].

% Lexicon: Assuming the roots have one syllable and the onset only contains the first phone.
underyaka([s,P1,P2],[root,free]):-   %/sIl/
    phone(P1),hih(P1),not(bck(P1)),not(mid(P1)),not(tns(P1)),
    phone(P2),alv(P2),cnt(P2),not(sib(P2)),not(pal(P2)).

underyaka([k,P1,P2],[root,free]):-  %/kIm/
    phone(P1),hih(P1),not(bck(P1)),not(mid(P1)),not(tns(P1)),
    phone(P2),nas(P2),lab(P2).

underyaka([j,P1,P2],[root,free]):-  %/jud/
    phone(P1),hih(P1),bck(P1),tns(P1),
    phone(P2),voi(P2),alv(P2),not(cnt(P2)),not(nas(P2)).

underyaka([n,P1,P2],[root,free]):-  %/nun/
    phone(P1),hih(P1),bck(P1),tns(P1),
    phone(P2),nas(P2),alv(P2).

underyaka([k,P1,P2],[root,free]):-  %/kud/
    phone(P1),hih(P1),bck(P1),tns(P1),
    phone(P2),voi(P2),alv(P2),not(cnt(P2)),not(nas(P2)).

underyaka([P1,P2,P1],[suffix,bound]):-  % nasal
    phone(P1),hih(P1),not(bck(P1)),not(mid(P1)), %/i/ /I/
    phone(P2),nas(P2),alv(P2).

underyaka([P1,P2,P1],[suffix,bound]):-  % not nasal
    phone(P1),hih(P1),not(bck(P1)),not(mid(P1)), %/i/ /I/
    phone(P2),alv(P2),cnt(P2),not(sib(P2)),not(pal(P2)).

% Perfective Formation
underyaka(Perfective,[perfective,free]):-
    underyaka(Root,[root,_]), 
    underyaka(Suffix,[suffix,_]),
    append(Root,Suffix,Perfective),
    % matching consonants
    last(Root,RootConsonant), 
    [_|[SuffixConsonant|_]] = Suffix,
    homorganic(RootConsonant,SuffixConsonant), 
    % matching vowels
    [SuffixVowel|_] = Suffix, 
    [_|[RootVowel|_]] = Root,
    homorganic(SuffixVowel,RootVowel).


% Surface Form
yaka(UnderSpecified,[word,free]):-
    underyaka(UnderSpecified,[_,free]).

homorganic(A,B):-
    tns(A) <=> tns(B), % true: matching /i/, false: matching /I/
    nas(A) <=> nas(B). % matching nasal consonants

