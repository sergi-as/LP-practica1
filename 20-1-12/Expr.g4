grammar Expr;

s : (modules)*;

modules: MOD ID declarations (definitions)+ END;

declarations: '(' ty ID (',' ty ID)*  ')';

ty: IN | OUT;

definitions: ID EQ expr ';' #assig
           | ID '(' ID (',' ID)* ')' ';' #moddef
           | WIRE ID (',' ID)* ';' #wiredef
           ;
expr: NOT ID
    | expr AND expr
    | expr OR expr
    | ID
    ;

MOD: 'module';
END: 'endmodule';
IN: 'input';
OUT: 'output';
WIRE: 'wire';
OR: 'or';
AND: 'and';
NOT: 'not';
EQ: '=';
ID: [a-z]+ [0-9]*;
WS : [ \t\n]+ -> skip ;
