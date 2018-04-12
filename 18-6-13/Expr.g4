grammar Expr;

s :(ruta)*;

ruta: ID ASSIG ID ID NUM #rutaLit
    | ID ASSIG expr #rutaExpr
    ;
expr: '(' expr ')' #parExpr
    | expr CONCAT expr #concatExpr
    | expr ALTER expr #alterExpr
    | ID #idExpr
    ;
ASSIG: ':=';
CONCAT: '+';
ALTER:  '|';
NUM: [0-9]+;
ID: [a-zA-Z]+ [0-9]*;
WS : [ \t\n]+ -> skip ;
