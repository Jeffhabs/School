( helper functions )

: 3dup ( x y z -- x y z x y z ) 
  dup 2over rot ; 

: 3drop ( x y z -- )
  drop 2drop ; 

: pack ( near m c -- packedstate ) 
  rot -100 * rot 10 * + + ;

: unpack ( packedstate -- near m c)
  dup 100 / -1 * swap dup 10 / 10 mod swap 10 mod
;

: printstate ( side m c -- )
   rot
   if ." [ near " swap . . ." ] " 
   else
   ." [ far " swap . . ." ] "
   then
;   

create used 100 cells allot
variable usedcounter

: isused ( n -- bool )
	\ assume false result
	0 swap
	\ loop through all elements
	usedcounter @ 0 do
		\ compare n with elt i
		dup used i cells + @
		= if nip -1 swap leave then
	loop
	drop
;

 : resetused ( -- ) 0 usedcounter ! ;
  
: addused ( n -- )
	used usedcounter @ cells + !
	1 usedcounter +!
;

create candidate 100 cells allot
variable candidatecounter

: resetcandidate ( -- ) 0 candidatecounter ! ;

: pushcandidate ( n -- )
  	candidate candidatecounter @ cells + !
	1 candidatecounter +!
;
: printcandidates ( -- )
  candidatecounter @ 0 = if ." empty "
  else
  cr
   candidatecounter
   @
   0
   cr ." candidate: "
   do
    cr candidate i cells + @ unpack printstate 
  loop
  then
;

: popcandidate ( -- n )
  -1 candidatecounter +!
  candidate candidatecounter @ cells + @
;

: startstate ( -- near m c ) true 3 3
;

: printused 
  usedcounter @ 0 = if ." empty "
  else
  usedcounter
  @
  0 
  do
  cr  used i cells + @ . 
  loop
  then
;

create crumb 100 cells allot
variable crumbCounter 

: resetcrumb ( -- ) 0 crumbCounter ! ;

: pushcrumb ( n -- )
  	crumb crumbCounter @ cells + !
	1 crumbCounter +!
;

: popcrumb ( -- n )
  -1 crumbCounter +! 
  crumb crumbCounter @ cells + @
;

: printcrumbs 
  crumbCounter @ 0 = if ." empty "
  else
  crumbCounter
  @
  0 
  do
   cr crumb i cells + @ unpack printstate
  loop
  then
;

: isgoal ( near m c -- bool )
  pack
  0 = if true
  else
  false
  then
;

: isvalid ( near m c -- bool )
  \ this seems to work perfectly
  \ are m and c between 0 and 3?
  \ if m == c or m is 0 or m is 3 use or's
  ROT		( m c side)
  DROP		( m c )
  DUP 0 >=      ( m c c ) \ is c > 0 ? 
  SWAP		( m bool c )
  DUP 3 <=	( m bool c bool ) \ is c <= 3?
  ROT		( m c bool bool )
  AND		( m c bool )

  ROT		( c bool m )
  DUP 0 >=	( c bool m bool )
  SWAP		( c bool bool m )
  DUP 3 <=	( c bool bool m bool )
  ROT		( c bool m bool bool )
  AND		( c bool m bool )

  ROT		( c m bool bool )
  AND		( c m bool ) 
  \ m == c
  -ROT ( bool c m )
  DUP ( bool c m m )
  ROT ( Bool m m c )  
  =   ( bool m bool )
  \ m is 0
  SWAP ( bool bool m )
  DUP	( bool bool m m )
  0=    ( bool bool m bool )
  
  SWAP ( bool bool bool m )
  3 =  ( bool bool bool bool ) 
  
  OR
  OR ( bool bool ) 

  AND
;

: addcandidate ( near m c -- )
  3dup
  isvalid invert if cr  ." invalid " printstate 
  else
  3dup pack isused if cr ." repeat " printstate
  else
  3dup pack dup addused pushcandidate cr ." fresh   " printstate
  then
  then 
; 

: successor ( near m c -- )
  \ m - 1 
  ROT	( m c near )
  DUP	( m c near near )
  if 1 + -rot ( bool m c )
  3dup ( bool m c bool m c ) 
  swap ( bool m c bool c m ) 
  1 -  ( bool m c bool c m -1 ) 
  swap ( bool m c bool m c ) 
  addcandidate ( near m c ) 
  \ m - 2
  3dup ( bool m c bool m c )
  swap ( bool m c bool c m ) 
  2 -  ( bool m c bool c m -2 ) 
  swap ( bool m c bool m c ) 
  addcandidate
  \ c - 1
  3dup ( bool m c bool m c ) 
  1 -  ( bool m c bool m c -1 )
  addcandidate
  \ c - 2
  3dup ( bool m c bool m c ) 
  2 -  ( bool m c bool m c -2 )
  addcandidate
  \ m -1 c - 1
  3dup ( bool m c bool m c )
  swap ( bool m c bool c m ) 
  1 -  ( bool m c bool c m -1 ) 
  swap ( bool m c bool m c ) 
  1 -  ( bool m c bool m c -1 )
  addcandidate
  else
  1 -
  \  m + 1 
   ROT	( c bool m)
  \ DUP	( m bool m m )
  3dup ( c bool m c bool m ) 
  rot ( bool m c )
  1 + ( m c bool m bool c ) 
    addcandidate ( c bool m )
   \ m + 2
  3dup ( c bool m c bool m ) 
  rot ( bool m c )
  2 + 
    addcandidate
  \ c + 1
  3dup ( c bool m c bool m ) 
  rot ( c bool m bool m c )
  1 + 
  addcandidate ( bool m c )
  \ c + 2
  3dup ( c bool m c bool m ) 
  rot ( c bool m bool m c )
  2 + ( c bool m bool m c ) 
  addcandidate
  \ m +1 c + 1
  3dup ( c bool m c bool m )
  rot  ( bool m c ) 
  swap ( c bool m bool c m )
  1 + 
  swap ( c bool m bool m c )
  1 + 
  addcandidate
  then
;

: search ( -- )
  printcandidates
  popcandidate
  dup
  pushcrumb   
  unpack
  3dup
  isgoal if cr ." solution found " cr ." -------------- "
  printcrumbs
  3drop
  else
  \ drop
  successor  ( bool m c bool )
  recurse 
  popcrumb
  then
; 

: start ( -- )
  resetused
  resetcrumb
  resetcandidate
  startstate
  pack
  dup
  pushcandidate
  addused
  search
;

\ when i pack any false 3 3 (33) and send to isused it doesnt work
\ check addcandidates with ian
\ check printstate
\ is successors suppose to swap 
