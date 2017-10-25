#header
<<
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

// struct to store information about tokens
typedef struct {
  string kind;
  string text;
} Attrib;

typedef struct{
    string value;
    string type;
}element;

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
#include <string>
//global structures
AST *root;
map <string,string> mont;
map <string,int> var;

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

/* intento 1: formato de  montaña 1u 2p 3d
 *
 *
 *
 */

//funciones del programa
char ita(int a){return '0'+a;}
//this was a mistake but its too late
int ati(string s,int & i){
    string n="";
    //cout<<"tespeta4: i:"<<i<<" s.size() "<<s.size()<<endl;
    while (i<s.size() and not(s[i]=='p' or s[i]=='u' or s[i]=='d')){
       // cout<<"extra: i,n:"<<i<<' '<<n<<endl;
       // if (s.size()>31)cout<<"dafuk"<<s[30]<<endl;
        //if (i==30) cout<<"me peta con: n:"<<n<<" de size: "<<n.size()<<" concatenado con el char s[i]: "<<s[i]<<" el resultado de '0'-s[i]: "<<'0'-s[i]<<endl;
        n+=s[i];
        i++;
       // cout<<"extra2: i,n:"<<i<<' '<<n<<endl;
    }
   // cout<<"tespeta5"<<endl;
    i--;
    return stoi(n);
}
int nlength(string s,int i){
    int l=0;
    while (i!=s.size() and not(s[i]=='p' or s[i]=='u' or s[i]=='d')){
        i++;
        l++;
    }
    return l;
}
string peak(int a,int b,int c){
    string s;
    s+=to_string(a); s+='u';
    s+=to_string(b); s+='p';
    s+=to_string(c); s+='d';
}
string peak(string a,string b,string c){
    string s;
    s+=a; s+='u';
    s+=b; s+='p';
    s+=c; s+='d';
    return s;
}

string valley(int a,int b,int c){
    string s;
    s+=to_string(a); s+='d';
    s+=to_string(b); s+='p';
    s+=to_string(c); s+='u';
}
string valley(string a,string b,string c){
    string s;
    s+=a; s+='d';
    s+=b; s+='p';
    s+=c; s+='u';
    return s;
}
bool match(string m1,string m2){return m1==m2;}

bool wellformed(string m){
    if (m.size()<6 or m[m.size()-1]=='p')return false;
    return true;

}
//solo complete si no esta wellformed
string complete(string ma){
    string m=ma;
    if (m.size()==2){
        char c=m[0];
        if (m[1]=='u') m=m+c+'p'+c+'d';
        else  m=m+c+'p'+c+'u';
    }
    else{
        char c=m[m.size()-4];
        if (m[m.size()-3]=='u')m=m+c+'d';
        else m=m+c+'u';
    }
    return m;
}

int height (string m){
    //cout<<"dentro de heigh con valor:"<<m<<endl;
    int max,min,curr;
    max=min=curr=0;

    for (int i=0;i<m.size();i+=2){
        int l=nlength(m,i);
            if (m[i + l] == 'u') {
                curr += ati(m, i);
                if (curr > max)max = curr;
            } else if (m[i + l] == 'd') {
                curr -= ati(m, i);
                if (curr < min)min = curr;
            }



    }
   // cout<<"max:"<<max<<"min:"<<min<<endl;
    if (min>=0) return max;
    else return max+(-min);
}

int height(string m,int& ma,int& length){

    int max,min,curr;
    max=min=curr=0;
    length=0;

    for (int i=0;i<m.size();i+=2){
        //cout<<"length: "<<length<<"num"<<ati(m[i])<<endl;
        int at=ati(m,i);
        length+=at;
        int l=nlength(m,i);
        if(m[i+l]=='u') {
            curr+=at;
            if (curr>max )max=curr;
        }
        else if (m[i+l]=='d') {
            curr-=at;
            if (curr<min)min=curr;
        }


    }
   // cout<<"max:"<<max<<"min:"<<min<<endl;
    ma=max;
    if (min>=0) return max;
    else return max+(-min);
}

void drawmat(const vector< vector<char> > & map ){
    for (int i=0;i<map.size();i++){
        for (int j=0;j<map[0].size();j++){
            cout<<map[i][j];
        }
        cout<<endl;
    }
}

//TODO: un D seguido de U o al reves me jode el dibujo, pruebalo
void drawi(string m,int h,int l,int ini){
    vector< vector<char> > map(h+2, vector<char>(l,' '));
    int x=0;
    int y=ini;
    //cout<<"size:"<<m.size()<<endl;
    for (int i=0;i<m.size();i+=2){
        //cout<<"tespeta1"<<endl;
        int le=nlength(m,i);
        //cout<<"tespeta2: "<<le<<endl;
        int n=ati(m,i);
        //cout<<"tespeta3"<<endl;
        //cout<<i<<' '<<m[i+1]<<' '<<n<<endl;
        switch(m[i+1]){
            case 'u':
                for (int j=0;j<n;j++){
                    map[y][x]='/';
                    x++;
                    y--;
                }
                if (m.size()>i+2+nlength(m,i+2) and m[i+2+nlength(m,i+2)]=='d')y++;
                break;
            case 'p':
                //cout<<"nooo0"<<' '<<n<<endl;
                for (int j=0;j<n;j++){
                   // cout<<"map leng "<<map[y].size()<<endl;
                    //cout<<"j"<<j<<" x "<<x<<" y "<<y<<endl;
                    //cout<<" m ap "<<map[y][x]<<endl;
                    map[y][x]='-';
                    x++;
                }
                if (m[i-le]=='u')y++;
                else y--;
               // cout<<"noo2"<<endl;
                break;
            default://case 'd
                for (int j=0;j<n;j++){
                    map[y][x]=92;  // ascii para \ pero no me dejaba ponerlo como '\'
                    x++;
                    y++;
                }
                if (m.size()>i+1+nlength(m,i+2)+1 and m[i+1+nlength(m,i+2)+1]=='u')y--;
                break;
        }
    }
    drawmat(map);
}


void draw(string mountain){
    int ma,l;
    int h=height(mountain,ma,l);
    //cout<<"petaya="<<endl;
    drawi(mountain,h,l,ma);
}

/*
 * tipos: bool mount int id
 */

element evaluate(AST *a) {
    element e; e.type=""; e.value="";
    if (a==NULL) return e;
    else if (a->kind == "intconst"){e.value=a->text;e.type="int";   }
    else if (a->kind == "+"){
        e.type="int";
        element r,l;
        r=evaluate(child(a,0));
        l=evaluate(child(a,1));
        int sum,a,b;
        if (r.type=="int")a=stoi(r.value);
        else if (r.type=="id")a=var[r.value];
        if (l.type=="int")b=stoi(l.value);
        else if (l.type=="id")b=var[l.value];
        sum=a+b;
        e.value=to_string(sum);

    }
    else if (a->kind == "id"){ e.value=a->text; e.type="id";} //todo decidir como gestiono id, decido aqui tipo o en execute asi como que hago con draw
    else if (a->kind == "*"){
        //el de la posicion 0, arriba en el dibujo
        element r,l;
        r=evaluate(child(a,0));
        l=evaluate(child(a,1));
        e.value=e.value+r.value+l.value;
        e.type="mount";
    }
    else if (a->kind==";"){
        element e2;
        e.type="mount";

        for (int i=0;i<2;i++){
            e2=evaluate(child(a,i));
            if (e2.type=="mount") e.value+=e2.value;
            else if (e2.type=="id") e.value+=mont[e2.value];
        }


    }
    else if (a->kind=="Peak"){
        e.type="mount";
        element e1,e2,e3;
        e1=evaluate(child(a,0));e2=evaluate(child(a,1));e3=evaluate(child(a,2));
        string par1,par2,par3;
        if (e1.type=="id")par1=to_string(var[e1.value]);
        else if (e1.type=="int")par1=e1.value;
        if (e2.type=="id")par2=to_string(var[e2.value]);
        else if (e2.type=="int")par2=e2.value;
        if (e3.type=="id")par3=to_string(var[e3.value]);
        else if (e3.type=="int")par3=e3.value;
        e.value=peak(par1,par2,par3);
    }
    else if (a->kind=="Valley"){
        e.type="mount";
        element e1,e2,e3;
        e1=evaluate(child(a,0));e2=evaluate(child(a,1));e3=evaluate(child(a,2));
        string par1,par2,par3;
        if (e1.type=="id")par1=to_string(var[e1.value]);
        else if (e1.type=="int")par1=e1.value;
        if (e2.type=="id")par2=to_string(var[e2.value]);
        else if (e2.type=="int")par2=e2.value;
        if (e3.type=="id")par3=to_string(var[e3.value]);
        else if (e3.type=="int")par3=e3.value;
        e.value=valley(par1,par2,par3);

    }
    else if(a->kind=="\\"){
        e.value='d';
    }
    else if(a->kind=="/"){
        e.value='u';
    }
    else if(a->kind=="-"){
        e.value='p';
    }
    //bool
    else if (a->kind=="AND"){
        e.type=="bool";
        bool result,br,bl;
        element r,l;
        r=evaluate(child(a,0));
        l=evaluate(child(a,1));
        //   cout<<endl<<"in AND with r ty: "<<r.type<< " and l ty: "<<l.type<<endl;
        //  cout<<endl<<"in AND with r value: "<<r.value<< " and l value: "<<l.value<<endl;
        if (l.type=="bool"){
            if (l.value=="true") bl=true;
            else bl=false;
        }
        if (r.type=="bool"){
            if (r.value=="true") br=true;
            else br=false;
        }
        //  cout<<"---br:"<<br<<"-bl:"<<bl<<endl;
        result=br and bl;
        if (result) e.value="true";
        else e.value="false";
        // cout<<"end AND with e.value"<<e.value;
    }
    else if (a->kind=="OR"){
        //cout<<"estoy en or"<<endl;
        e.type=="bool";
        bool result,br,bl;
        element r,l;
        r=evaluate(child(a,0));
        l=evaluate(child(a,1));
        if (l.type=="bool"){
            if (l.value=="true") bl=true;
            else bl=false;
        }
        if (r.type=="bool"){
            if (r.value=="true") br=true;
            else br=false;
        }
        result=br or bl;
        if (result) e.value="true";
        else e.value="false";

    }
    else if (a->kind=="NOT"){
        //  cout<<"estoy en not"<<endl;
        e.type="bool";
        element e1=evaluate(child(a,0));
        //  cout<<"e1 type: "<<e1.type<<" e1 val: "<<e1.value<<endl;
        if (e1.type=="bool"){
            if (e1.value=="true")e.value="false";
            else e.value="true";
        }
        //  cout<<"salgo de not: "<<e1.value<<" "<<e.value<<endl;
    }
    else if (a->kind=="<"){
        e.type="bool";
        element r,l;
        int ir,il;
        r=evaluate(child(a,0));
        l=evaluate(child(a,1));
       //  cout<<"inside < r.val "<<r.value<<" l.val "<<l.value<<endl;
        if (l.type=="int"){
            il=stoi(l.value);
        }
        else il=var[l.value];
        if (r.type=="int"){
            ir=stoi(r.value);
        }
        else ir=var[r.value];
        //cout<<"il: "<<il<<" ir:"<<ir<<endl;
        if (ir<il)e.value="true";
        else e.value="false";
        //cout<<"end < with e.value:"<<e.value<<endl;

    }
    else if (a->kind==">"){
        e.type="bool";
        element r,l;
        int ir,il;
        r=evaluate(child(a,0));
        l=evaluate(child(a,1));
        if (l.type=="int"){
            il=stoi(l.value);
        }
        else il=var[l.value];
        if (l.type=="int"){
            ir=stoi(r.value);
        }
        else ir=var[r.value];
        if (ir>il)e.value="true";
        else e.value="false";

    }
    else if (a->kind=="=="){
        e.type="bool";
        element r,l;
        int ir,il;
        r=evaluate(child(a,0));
        l=evaluate(child(a,1));
        if (l.type=="int"){
            il=stoi(l.value);
        }
        else il=var[l.value];
        if (l.type=="int"){
            ir=stoi(r.value);
        }
        else ir=var[r.value];
        if (il==ir)e.value="true";
        else e.value="false";
      //  cout<<"il: "<<il<<" ir:"<<ir<<endl;
    }
    else if (a->kind=="Wellformed"){
        // cout<<"entro en wellformed"<<endl;
        e.type="bool";
        element r=evaluate(child(a,0));
        if (r.type=="mount") {
            if (wellformed(r.value))e.value="true";
            else e.value="false";
        }
        else if (r.type=="id"){
            //cout<<"well con id"<<endl;
            if (wellformed(mont[r.value]))e.value="true";
            else e.value="false";
        }
        //if (wellformed(child(a,0)->text))e.value="true";
        // cout<<"salgo de well con valor"<<e.value<<endl;
    }
    else if (a->kind=="Match"){
        e.type="bool";
        if (match(child(a,0)->text,child(a,1)->text))e.value="true";
        else e.value="false";
    }
    else if (a->kind=="Height"){
        e.type="int";
        element r=evaluate(child(a,0));
        if (r.type=="mount") e.value=to_string(height(r.value));
        else if (r.type=="id")e.value=to_string(height(mont[r.value]));
        // cout<<"heigh: "<<e.value<<endl;
    }
    else{//resto de kinds con los que no hago nada especial
        e.value=a->kind;
    }
    return e;
}


void execute(AST *a) {
    if (a == NULL) return;

    for(int i=0;child(a,i)!= NULL ;i++){
        AST *b=child(a,i);
        if (b->kind=="is"){
            element e=evaluate(child(b,1));
            //cout<<e.type<<" valor:"<<e.value<<endl;
            if (e.type=="mount"){
                 mont[child(b,0)->text]=e.value;
            }
            else if (e.type=="int"){
                var[child(b,0)->text]=stoi(e.value);
            }
        }
        else if (b->kind=="Draw"){
            element e=evaluate(child(b,0));
            if (e.type=="id") {
               // cout<<"ID to draw: "<<e.value<<" Value: "<<mont[e.value]<<endl;
                draw(mont[e.value]);
            }
            else if (e.type=="mount")  draw(e.value);
            else cout<<"TYPE ERROR: parametro para Draw no es una montaña"<<endl;

        }
        else if (b->kind=="Complete"){
            element e=evaluate(child(b,0));
            if (e.type!="id" or  mont.count(e.value)==0 ) cout<<"TYPE ERROR: parametro para Complete no es una montaña"<<endl;
            else{
                mont[e.value]=complete(mont[e.value]);
            }
        }

        else if (b->kind=="if"){
            //cout<<"ghi"<<endl;
            element e= evaluate(child(b,0));
            //cout<<e.type<<" vool value "<< e.value<<endl;
             if (e.value=="true"){
                execute(child(b,1));
            }
        }
        else if (b->kind=="while"){
            while ((evaluate(child(b,0))).value=="true"){
                //cout<<"inside while"<<endl;
                execute(child(b,1));
                //cout<<"executed while"<<endl;
            }
          //  cout<<"khe"<<endl;
        }
    }
}

int main() {
  root = NULL;
  ANTLR(mountains(&root), stdin);
  ASTPrint(root);
  execute(root);
   // cout<<"se ejecuta"<<endl;
  map<string,string>::iterator it;
   for (it=mont.begin();it!=mont.end();it++){
        if (wellformed(it->second)){
            cout<<"l'altitud final de "<<it->first<<" és: "<<height(it->second)<<endl;
            draw(it->second);

        }
   }

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


assign: ID IS^ (expr|pv|varas);
//separado para tener la jerarquia en el arbol
expr: (part|other) (CONC^ (part2|other|pv))*;// una sin concat y las siguientes si
//todo: esto... me peta con k is 1 pero solo si es la ultima instruccion
part: NUM ((STAR^ (UP|DOWN|PEAK))|(PLUS^ (NUM|ID))*);   //numero,estrella y tipo de parte
part2:NUM STAR^ (UP|DOWN|PEAK);

varas:ID (PLUS^ (ID|NUM))*;

//voy a mejorar esta parte
other: SHARP! ID; // #Mx

pv: (PEAK^|VALLEY^)LPAR! (NUM|calc) COMA! (NUM|calc) COMA! (NUM|calc) RPAR!; //peak valley
calc:ID (PLUS^ (NUM|ID))*; //todo no acepta suma de solo numeros

func: (MATCH^ m|WELL^ w);//funciones que devuelven bool
m: LPAR! other COMA! other RPAR!; //match
w: LPAR! ID RPAR!;

heigh: HEIGHT^ LPAR! other RPAR!; //heigh

condic: IF^ LPAR!  boole RPAR! mountains ENDIF!;

iter: ITER^ LPAR!  boole RPAR! mountains ENDWHILE!;



/*
boole: ( (NOT^|) booleaux1) ( (AND^|OR^) (NOT^|) booleaux1)*;
booleaux1: func|heigh (LESS^|MORE^|EQUALS^) NUM;
*/

boole:  booland (OR^ booland)*;
booland:  boolnot (AND^ boolnot)*;
boolnot: (NOT^|) boolatom;
boolatom: func|heigh (LESS^|MORE^|EQUALS^) NUM;


draw: DRAW^ LPAR! expr RPAR!;
complete: COMPLETE^ LPAR! ID RPAR!;
//git test re
