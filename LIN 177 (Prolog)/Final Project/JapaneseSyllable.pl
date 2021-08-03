% reference:
% https://en.wikipedia.org/wiki/Help:IPA/Japanese
% https://en.wikipedia.org/wiki/Japanese_phonology
:- ['fulldisplay.pl'].

% phones
% vowels 
%あ ä low central unrounded vowel
phone(A):- name(A,[97]).
vow(A):- name(A,[97]).  
low(A):- name(A,[97]).
ctr(A):- name(A,[97]).
unr(A):- name(A,[97]).

%い i high front unrounded vowel
phone(A):- name(A,[105]). 
vow(A):- name(A,[105]).
hih(A):- name(A,[105]).
unr(A):- name(A,[105]). 
frt(A):- name(A,[105]). 

%う ɯ high back unrounded vowel
phone(A):- name(A,[623]).
vow(A):- name(A,[623]).
hih(A):- name(A,[623]).
bck(A):- name(A,[623]).
unr(A):- name(A,[623]).

%え e̞ mid front unrounded vowel
phone(A):- name(B,[101]),name(C,[798]),atom_concat(B,C,A). 
vow(A):- name(B,[101]),name(C,[798]),atom_concat(B,C,A). 
mid(A):- name(B,[101]),name(C,[798]),atom_concat(B,C,A). 
frt(A):- name(B,[101]),name(C,[798]),atom_concat(B,C,A).  
unr(A):- name(B,[101]),name(C,[798]),atom_concat(B,C,A).  

%お o̞ mid back rounded vowel
phone(A):- name(B,[111]),name(C,[798]),atom_concat(B,C,A).  
vow(A):- name(B,[111]),name(C,[798]),atom_concat(B,C,A).  
mid(A):- name(B,[111]),name(C,[798]),atom_concat(B,C,A). 
bck(A):- name(B,[111]),name(C,[798]),atom_concat(B,C,A). 
rnd(A):- name(B,[111]),name(C,[798]),atom_concat(B,C,A). 

% Consonants: not(vow(P))
%k: voiceless velar stop
phone(A):- name(A,[107]).
vel(A):- name(A,[107]).
stp(A):- name(A,[107]). 
%かきくけこ　aspirated

%g: voiced velar stop
%がぎぐげご　
phone(A):- name(A,[609]).
voi(A):- name(A,[609]).
vel(A):- name(A,[609]).
stp(A):- name(A,[609]).

%kʲ palatalized k
phone(A):- name(B,[107]),name(C,[690]),atom_concat(B,C,A). 
pal(A):- name(B,[107]),name(C,[690]),atom_concat(B,C,A). 
vel(A):- name(B,[107]),name(C,[690]),atom_concat(B,C,A). 
stp(A):- name(B,[107]),name(C,[690]),atom_concat(B,C,A). 
%きゅ

%s: voiceless alveolar fricative 
phone(A):- name(A,[115]).
alv(A):- name(A,[115]).
fri(A):- name(A,[115]).
%さしすせそ (しis actually /ɕi/) 

%dʑ: voiced alveolo-palatal sibilant affricate
phone(A):- name(A,[677]).
voi(A):- name(A,[677]).
alv(A):- name(A,[677]).
pal(A):- name(A,[677]).
sib(A):- name(A,[677]).
afr(A):- name(A,[677]).
％じゅ jyu


%t: voiceless alveolar, stop
phone(t).
phone(A):- name(A,[116]).
alv(A):- name(A,[116]).
stp(A):- name(A,[116]).
%た__てと aspirated

%tɕ:voiceless alveolo-palatal sibilant affricate
phone(A):- name(A,[680]).
alv(A):- name(A,[680]).
pal(A):- name(A,[680]).
sib(A):- name(A,[680]).
afr(A):- name(A,[680]).
%ち aspirated

%ts: voiceless alveolar sibilant affricate
phone(A):- name(A,[678]).
alv(A):- name(A,[678]).
sib(A):- name(A,[678]).
afr(A):- name(A,[678]).
%つ aspirated

%n: voiced alveolar nasal
phone(A):- name(A,[110]).
voi(A):- name(A,[110]).
alv(A):- name(A,[110]).
nas(A):- name(A,[110]).
%なにぬねの 

%h:voiceless glottal fricative
phone(A):- name(A,[104]).
glt(A):- name(A,[104]).
fri(A):- name(A,[104]).
%は_ふへほ aspirated　(ふ is actually/ɸi/)

%ç: voiceless palatal fricative
phone(A):- name(A,[231]).
pal(A):- name(A,[231]).
fri(A):- name(A,[231]).
%ひ aspirated

%p:voiceless bilabial stop
phone(A):- name(A,[112]).
lab(A):- name(A,[112]).
stp(A):- name(A,[112]).
%ぱぴぷぺぽ 

%b: voiced bilabial stop
phone(A):- name(A,[98]).
voi(A):- name(A,[98]).
lab(A):- name(A,[98]).
stp(A):- name(A,[98]).
%ばびぶべぼ 

%ɾ: voiced alveolar flap
phone(A):- name(A,[638]).
voi(A):- name(A,[638]).
alv(A):- name(A,[638]).
flp(A):- name(A,[638]).
%らりるれろ 

%j: voiced palatal approximant, or yod
phone(A):- name(A,[106]).
voi(A):- name(A,[106]).
pal(A):- name(A,[106]).
yod(A):- name(A,[106]).
%やゆよ 

%ん ɴ:vd uvular nasal　
phone(A):- name(A,[628]).
uvu(A):- name(A,[628]).
nas(A):- name(A,[628]).
notPrefix(A):- name(A,[628]).

%っ ʔ Glottal stop
phone(A):- name(A,[660]).
glt(A):- name(A,[660]).
stp(A):- name(A,[660]).
notPrefix(A):- name(A,[660]).

% Syllable formation
% one-phone syllables: vowel or ん/っ
syllable([A]):-
phone(A),(vow(A);notPrefix(A)).

% two-phone syllables: consonant+vowel
syllable(A):- 
phone(Vowel),vow(Vowel),
phone(Consonant),not(vow(Consonant)),
not(afr(Consonant)),
not(notPrefix(Consonant)), % syllable cannot start with ん/ɴ　nor っ/ʔ
permutation([Consonant,Vowel],A),
last(A,Vowel).

% palatalized two-phone syllables:
%きゃ　きゅ　きょ
syllable(A):-　
phone(Vowel),vow(Vowel),not(frt(Vowel)), %only /a/,/ɯ/,/o/
phone(Consonant),not(vow(Consonant)), 
not(notPrefix(Consonant)),
pal(Consonant),vel(Consonant),stp(Consonant),%kʲ
permutation([Consonant,Vowel],A),
last(A,Vowel).

% affricate two-phone syllables:

%じゃ　じゅ　じょ
syllable(A):-　
phone(Vowel),vow(Vowel),not(frt(Vowel)), %only /a/,/ɯ/,/o/
phone(Consonant),not(vow(Consonant)),voi(Consonant), 
afr(Consonant),not(notPrefix(Consonant)),%ʥ
permutation([Consonant,Vowel],A),
last(A,Vowel).

%ち/つ
syllable(A):-　
phone(Vowel),vow(Vowel),hih(Vowel), % /i/,/ɯ/
phone(Consonant),not(vow(Consonant)),
afr(Consonant),not(notPrefix(Consonant)),
not(voi(Consonant)), %tɕ/ts
((frt(Vowel),pal(Consonant)); %ち
(bck(Vowel),not(pal(Consonant)))), %つ
append([Consonant],[Vowel],A).


%Aspirated syllables
aspirated(A):-
syllable(A),[C,_] = A,
(not(voi(C)),stp(C),not(lab(C)),not(pal(C)),not(glt(C)); %k/t
(glt(C),fri(C)); %h
(afr(C),not(voi(C)))). %tɕ/ts

/* consonants and syllables that are not present in numbers or counters are ommited:
ざじずぜぞ　z
だぢづでど d
まみむめも m
わを w
Yōons except kyu and jyu
*/

