#header
<<
#include <string>
#include <iostream>
using namespace std;

// struct to store information about tokens
typedef struct {
  string kind;
  string text;
} Attrib;

// function to fill token information (predeclaration)
void zzcr_attr(Attrib *attr, int type, char *text);

// fields for AST nodes
#define AST_FIELDS string kind; string text;
#include "ast.h"

// macro to create a new AST node (and function predeclaration)
#define zzcr_ast(as,attr,ttype,textt) as=createASTnode(attr,ttype,textt)
AST* createASTnode(Attrib* attr, int ttype, char *textt);
>>

<<
#include <cstdlib>
#include <cmath>

//global structures
AST *root;


// function to fill token information
void zzcr_attr(Attrib *attr, int type, char *text) {
   if (type == ID) {
    attr->kind = "id";
    attr->text = text;
   }
   else if (type==NUM){
    attr->kind= "intconst";
    attr->text = text;
   }
   else {
    attr->kind = text;
    attr->text = "";
   }
}

// function to create a new AST node
AST* createASTnode(Attrib* attr, int type, char* text) {
  AST* as = new AST;
  as->kind = attr->kind; 
  as->text = attr->text;
  as->right = NULL; 
  as->down = NULL;
  return as;
}

/// create a new "list" AST node with one element
AST* createASTlist(AST *child) {
  AST *as = new AST;
  as->kind = "list";
  as->right = NULL;
  as->down = child;
  return as;
}

/// get nth child of a tree. Count starts at 0.
/// if no such child, returns NULL
AST* child(AST *a, int n) {
  AST *c = a->down;
  for (int i=0; c!=NULL && i<n; i++) c = c->right;
  return c;
}


/// print AST, recursively, with indentation
void ASTPrintIndent(AST *a, string s) {
  if (a == NULL) return;

  cout << a->kind;
  if (a->text != "") cout << "(" << a->text << ")";
  cout << endl;

  AST *i = a->down;
  while (i != NULL && i->right != NULL) {
    cout << s+"  \\__";
    ASTPrintIndent(i, s+"  |"+string(i->kind.size()+i->text.size(), ' '));
    i = i->right;
  }
  
  if (i != NULL) {
    cout << s+"  \\__";
    ASTPrintIndent(i, s+"   "+string(i->kind.size()+i->text.size(), ' '));
    i = i->right;
  }
}

/// print AST 
void ASTPrint(AST *a) {
  while (a != NULL) {
    cout << " ";
    ASTPrintIndent(a, "");
    a = a->right;
  }
}


int main() {
  root = NULL;
  ANTLR(mountains(&root), stdin);
  ASTPrint(root);
}
>>


#lexclass START
//funciones
#token DRAW "Draw"
#token COMPLETE "Complete"
#token PEAK "Peak"
#token VALLEY "Valley"
#token MATCH "Match"
#token HEIGHT "Height"
#token WELL "Wellformed"

//flow control
#token ITER "while"
#token ENDWHILE "endwhile"
#token IF "if"
#token ENDIF "endif"

//logical operators
#token OR "OR"
#token AND "AND"
#token NOT "NOT"
#token LESS "\<"
#token MORE "\>"
#token EQUALS "=="

#token PLUS "\+"




//simbolos  y resto
#token UP "\/"
#token DOWN "\\"
#token PEAK "\-"
#token CONC "\;"
#token STAR "\*"
#token SHARP "\#"
#token LPAR "\("
#token RPAR "\)"
#token COMA ","
#token IS "is"
#token ID "[a-zA-Z][0-9]*"
#token NUM "[0-9]+"
#token SPACE "[\ \t \n]" << zzskip(); >>

//Montaña en general
mountains: (assign | condic | draw | iter | complete)* << #0 = createASTlist(_sibling); >>;
//...

//asignaciones de Mx is .....
assign: ID IS^ (expr|pv);
//separado para tener la jerarquia en el arbol
expr: (part|other)+ (CONC^ (part|other|pv))*;// una sin concat y las siguientes si
/*TODO: AHORA CUALQUIER COMBINACION VALE SOLO TIENE QUE ACEPTAR LAS CORRECTAS*/
part: NUM (STAR^ (UP|DOWN|PEAK)|); //numero,estrella y tipo de parte
other: SHARP! ID; // #Mx

pv: (PEAK^|VALLEY^)LPAR! (NUM|calc) COMA! (NUM|calc) COMA! (NUM|calc) RPAR!; //peak valley
calc:ID (PLUS^ NUM|);

func: (MATCH^ m|WELL^ w);//funciones que devuelven bool
m: LPAR! other COMA! other RPAR!; //match
w: LPAR! ID RPAR!;

heigh: HEIGHT^ LPAR! other RPAR!; //heigh

condic: IF^ LPAR!  boole RPAR! mountains ENDIF!;

iter: ITER^ LPAR!  boole RPAR! mountains ENDWHILE!;


//boole: ( (NOT|) boole2) ((NOT|) boole2)*
//boole2:
//TODO: no se definir prioridad de and,or,not sin liarlo todo
boole: ( (NOT^|) booleaux1)+ ( (AND^|OR^) (NOT^|) booleaux1)*;
booleaux1: func|heigh (LESS^|MORE^|EQUALS^) NUM;
/*
boole: ( (NOT^|) booleaux1)+ ( booleaux1 (NOT^|) booleaux1)*;
booleaux1: (OR^|booleaux2);
booleaux2:  (AND^|booleaux3);
booleaux3: (func|heigh) (LESS^|MORE^|EQUALS^) NUM; */


draw: DRAW^ LPAR! expr RPAR!;
complete: COMPLETE^ LPAR! ID RPAR!;
//git test re
