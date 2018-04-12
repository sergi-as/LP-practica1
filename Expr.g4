grammar Expr;

s : cmp ;
cmp: e bop=(EQ|LT|GT|LE|GE) e #compar 
  | e #oper
  ; 
e : LP e RP #par 
  | e op=(MULT|DIV) e    # prod
  | e op=(ADD|SUB) e     # plus
  | INT         # value
  ;
  
EQ: '=' ;
LT: '<' ;
GT: '>' ;
LE: '<=';
GE: '>=';  
LP: '(' ;
RP: ')' ;  
DIV: '/' ;
MULT: '*' ;
ADD : '+' ;
SUB : '-' ;
INT : [0-9]+ ;
WS : [ \t\n]+ -> skip ;

