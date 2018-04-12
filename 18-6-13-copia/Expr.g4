grammar Expr;

s :(definicions)*;

definicions: 'graph' ID '(' parList ')' (defs ';')* 'endgraph';

parList: (ID (',' ID)*)?;

defs: ID ('>' ID)+ #pathdef
    | ID '('parlist ')'
    ;


NUM: [0-9]+;
ID: [a-zA-Z]+ [0-9]*;
WS : [ \t\n]+ -> skip ;
