
#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include "ExprBaseListener.h"
#include "tree/ParseTreeWalker.h"
#include "tree/ParseTreeProperty.h"

#include <iostream>
#include <fstream>
#include <stack>
#include <cstdio>    // fopen

// using namespace std;
// using namespace antlr4;




//////////////////////////////////////////////////////////////////////
// Sample "calculator" using tree properties not stack
class EvaluatorWithProps : public ExprBaseListener {
public:

  antlr4::tree::ParseTreeProperty<int> values;
  std::map<std::string,bool> used;
  std::map<std::string,bool> isOut;

  virtual void enterS(ExprParser::SContext * ctx)  { }
  virtual void exitS(ExprParser::SContext * ctx)  { }

  virtual void enterModules(ExprParser::ModulesContext * ctx)  { }
  virtual void exitModules(ExprParser::ModulesContext * ctx)  { }

  virtual void enterDeclarations(ExprParser::DeclarationsContext * ctx)  { }
  virtual void exitDeclarations(ExprParser::DeclarationsContext * ctx){
    for (uint i=0;i<ctx->ID().size();i++){
      used[ctx->ID(i)->getText()]=false;
      if (ctx->ty(i)->getText() == "output"){
        isOut[ctx->ID(i)->getText()]=true;
      }
    }
  }

  virtual void enterAssig(ExprParser::AssigContext * ctx)  { }
  virtual void exitAssig(ExprParser::AssigContext * ctx)  { }

  virtual void enterModdef(ExprParser::ModdefContext * ctx)  { }
  virtual void exitModdef(ExprParser::ModdefContext * ctx)  {
    for (auto id:ctx->ID())
      used[id->getText()]=true;
  }

  virtual void enterWiredef(ExprParser::WiredefContext * ctx)  { }
  virtual void exitWiredef(ExprParser::WiredefContext * ctx)  {
    for (auto id:ctx->ID())
      used[id->getText()]=false;

  }

  virtual void enterExpr(ExprParser::ExprContext * ctx)  { }
  virtual void exitExpr(ExprParser::ExprContext * ctx)  {
    if (ctx->ID()){
      std::cout<<"id: "<<ctx->ID()->getText()<<std::endl;
      used[ctx->ID()->getText()]=true;
    }



 }};
// Sample "calculator" using tree properties not stack
//////////////////////////////////////////////////////////////////////


int main(int argc, const char* argv[]) {
  // check the correct use of the program
  if (argc != 2) {
    std::cout << "Usage: ./main <file>" << std::endl;
    return EXIT_FAILURE;
  }
  if (not std::fopen(argv[1], "r")) {
    std::cout << "No such file: " << argv[1] << std::endl;
    return EXIT_FAILURE;
  }

  // open input file and create a character stream
  std::ifstream stream;
  stream.open(argv[1]);
  antlr4::ANTLRInputStream input(stream);

  // create a lexer that consumes the character stream and produce a token stream
  ExprLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  // create a parser that consumes the token stream, and parses it.
  ExprParser parser(&tokens);

  // call the parser and get the parse tree
  antlr4::tree::ParseTree *tree = parser.s();

  // print the parse tree (for debugging purposes)
  std::cout << tree->toStringTree(&parser) << std::endl;

  ////////////////////////////////////////////////////////////////////

  // create a walker that will traverse the tree
  antlr4::tree::ParseTreeWalker walker;





  // Create a second listener (with Properties) that will evaluate the expression
  EvaluatorWithProps eval2;

  // Traverse the tree using this EvaluatorWithProps
  walker.walk(&eval2, tree);

  // Dump the result (accessing the root node property)
  std::cout << "result with tree props = " << eval2.values.get(tree) << std::endl;

  for (auto e:eval2.used){
    if (not e.second)
      std::cout<<"ERROR: elemento no usado "<<e.first<<std::endl;
  }

  return EXIT_SUCCESS;
}
