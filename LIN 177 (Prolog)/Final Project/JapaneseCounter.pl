:- ['JapaneseSyllable.pl'].
:- ['entailment.pl'].
%Number Lexicon, format:([Syllable_list],[Type,value])
%1 いち
underjpn([[i],S],[number,1]):-
    syllable(S),[C,V] = S,
    afr(C),pal(C),frt(V).
%2　に
underjpn([S],[number,2]):-
    syllable(S),[C,V] = S,
    voi(C),alv(C),nas(C), %n
    vow(V),hih(V),frt(V). %i
%3　さん
underjpn([S1,S2],[number,3]):-
    syllable(S1),[C1,V1] = S1,alv(C1),fri(C1),low(V1),
    syllable(S2),[C2] = S2,uvu(C2),nas(C2).
%4　よん
underjpn([S1,S2],[number,4]):-
    syllable(S1),[C1,V1] = S1,yod(C1),mid(V1),bck(V1),
    syllable(S2),[C2] = S2,uvu(C2),nas(C2).
%5　ご
underjpn([S],[number,5]):-
    syllable(S),[C,V] = S,
    voi(C),vel(C),stp(C),mid(V),bck(V).
%6  ろく
underjpn([[ɾ,o̞],S],[number,6]):-
    syllable(S),[C,V] = S,
    not(voi(C)),not(pal(C)),vel(C),stp(C),
    hih(V),bck(V).
%7　なな
underjpn([S,S],[number,7]):-
    syllable(S),[C,V] = S,
    voi(C),alv(C),nas(C),low(V).
%8  はち
underjpn([[h,a],S],[number,8]):-
    syllable(S),[C,V] = S,
    afr(C),pal(C),frt(V).
%9　きゅう
underjpn([S1,S2],[number,9]):-
    syllable(S1),[C1,V1] = S1,
    pal(C1),vel(C1),hih(V1), bck(V1), %kʲ, ɯ
    syllable(S2),[V2]=S2, hih(V2), bck(V2). %ɯ
%10　じゅう
underjpn([S1,S2],[number,10]):-
    syllable(S1),[C1,V1] = S1,
    voi(C1), afr(C1),hih(V1), bck(V1), %ʥ, ɯ
    syllable(S2),[V2]=S2, hih(V2), bck(V2). %ɯ

%Counter Lexicon, format:([Syllable_list],[Type,basic_form])

%本 hon,pon,bon
underjpn([S,[ɴ]],[counter,hon]):-
    syllable(S),[C,V] = S,
    hpb(C),
    mid(V),bck(V).
%杯 hai,pai,bai
underjpn([S,[i]],[counter,hai]):-
    syllable(S),[C,V] = S,
    hpb(C),
    low(V).
%匹 hiki,piki,biki
underjpn([S,[k,i]],[counter,hiki]):-
    syllable(S),[C,V] = S,
    hpb(C),
    hih(V),frt(V).

% the natural class for phone h,p,b
hpb(X):-
phone(X),not(vow(X)),
not(notPrefix(X)),not(nas(X)),not(afr(X)),
not(alv(X)),not(pal(X)),not(vel(X)),not(uvu(X)).

% Aspirated Sounds: syllables that start with k,s,t,h
homorganic(A,B):-
aspirated(A) <=> aspirated(B).


/* Rules:
    1.The last syllable of two-syllable number(S1) and the first syllable of counter(S2) are both aspirated
        S1 is replaced by [ʔ]; consonant of S2 becomes [p]
            いちほん [i,ti,ho,n] → いっぽん [i,ʔ,po,n];　
            ろくほん [ro,ku,ho,n] → ろっぽん [ro,ʔ,po,n].　
    2.For number 10[ʥu,u],the syllable after S1 is replaced by [ʔ];
        the consonant of counter's first syllable(S2) becomes [p]
            じゅうほん[ʥu,u,ho,n]→じゅっぽん[ʥu,ʔ,po,n]
    3.For number 3[sa,n],the consonant becomes voiced:
            さんほん[sa,n,ho,n]→さんぼん[sa,n,bo,n] voiced:h->b k->g           
*/
%Number-Counter Phrase Formation

japanese(Number):-
    underjpn(Number,[number,_]).

japanese(AllPhrase):-
    underjpn(_,[number,A]),
    underjpn(_,[counter,B]),
    (japanese0(AllPhrase,A,B);
    japanese1(AllPhrase,A,B);
    japanese2(AllPhrase,A,B);
    japanese3(AllPhrase,A,B)).

japanese(DesiredPhrase,A,B):-
    japanese0(DesiredPhrase,A,B);
    japanese1(DesiredPhrase,A,B);
    japanese2(DesiredPhrase,A,B);
    japanese3(DesiredPhrase,A,B).


japanese0(DesiredPhrase,A,B):- %general case
    underjpn(Number,[number,A]),
    underjpn(Counter,[counter,B]),
    append(Number,Counter,DesiredPhrase),
    not(japanese1(_,A,_)),not(japanese2(_,A,_)),not(japanese3(_,A,_)),
    [FirstS|_]=Counter,[FirstP|_] = FirstS, glt(FirstP),fri(FirstP). % limit to [h]
    

japanese1(DesiredPhrase,A,B):-  %rule 1
    underjpn(Number,[number,A]),
    underjpn(Counter,[counter,B]),
    append([[NumHeadS,[P]],Counter],DesiredPhrase),
    phone(P),glt(P),stp(P),%append [ʔ]
    [NumHeadS,NumTailS]=Number, [FirstS|_]=Counter,
    aspirated(NumTailS),
    not(homorganic(NumTailS,FirstS)), % the last syllable of number and the first syllable of counter cannot be both aspirated
    [FirstP|_] = FirstS, not(voi(FirstP)). %limit to [p]

japanese2(DesiredPhrase,A,B):-  %rule 2
    underjpn(Number,[number,A]),
    underjpn(Counter,[counter,B]),
    append([[NumHeadS,[P]],Counter],DesiredPhrase),
    phone(P),glt(P),stp(P),%append [ʔ]
    [NumHeadS|_]=Number, [NumFirstP|_] = NumHeadS, afr(NumFirstP),voi(NumFirstP), % NumFirstP = [ʥ]
    [CntFirstS|_]=Counter,[CntFirstP|_] = CntFirstS, not(voi(CntFirstP)),stp(CntFirstP). %limit to [p]

japanese3(DesiredPhrase,A,B):-  %rule 3
    underjpn(Number,[number,A]),
    underjpn(Counter,[counter,B]),
    append([Number,Counter],DesiredPhrase),
    [NumHeadS,NumTailS]=Number, [NumFirstP|_] = NumHeadS, alv(NumFirstP),fri(NumFirstP), % Number = [sa,n]
    [FirstS|_]=Counter,[FirstP|_] = FirstS, voi(FirstP). %limit to [b]
