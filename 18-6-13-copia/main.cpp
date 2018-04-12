
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
  antlr4::tree::ParseTreeProperty <std::string> origen;
  antlr4::tree::ParseTreeProperty <std::string> desti;
  std::map <std::string,antlr4::ParserRuleContext * > ruta;

  virtual void enterS(ExprParser::SContext * ctx)  { }
  virtual void exitS(ExprParser::SContext * ctx)  { }

  virtual void enterRutaLit(ExprParser::RutaLitContext * ctx)  {
   }
  virtual void exitRutaLit(ExprParser::RutaLitContext * ctx)  {
    origen.put(ctx,ctx->ID(1)->getText());
    desti.put(ctx,ctx->ID(2)->getText());
    ruta[ctx->ID(0)->getText()]=ctx;
   }

  virtual void enterRutaExpr(ExprParser::RutaExprContext * ctx)  { }
  virtual void exitRutaExpr(ExprParser::RutaExprContext * ctx)  {
    origen.put(ctx, origen.get(ctx->expr()) );
    desti.put(ctx, desti.get(ctx->expr()) );
    ruta[ctx->ID()->getText()]=ctx;
  }

  virtual void enterParExpr(ExprParser::ParExprContext * ctx)  { }
  virtual void exitParExpr(ExprParser::ParExprContext * ctx)  {
    origen.put(ctx, origen.get(ctx->expr()) );
    desti.put(ctx, desti.get(ctx->expr()) );
   }

  virtual void enterAlterExpr(ExprParser::AlterExprContext * ctx)  { }
  virtual void exitAlterExpr(ExprParser::AlterExprContext * ctx)  {
    if (origen.get(ctx->expr(0)) != origen.get(ctx->expr(1)))
      std::cout<<"ERROR: origens diferents a alternatives"<<std::endl;
    if (desti.get(ctx->expr(0)) != desti.get(ctx->expr(1)))
      std::cout<<"ERROR: destins diferents a alternatives"<<std::endl;
    origen.put(ctx,origen.get(ctx->expr(0)));
    desti.put(ctx,desti.get(ctx->expr(0)));
   }

  virtual void enterIdExpr(ExprParser::IdExprContext * ctx)  { }
  virtual void exitIdExpr(ExprParser::IdExprContext * ctx)  {
    origen.put(ctx, origen.get(ruta[ctx->getText()]) );
    desti.put(ctx, desti.get(ruta[ctx->getText()]) );
  }

  virtual void enterConcatExpr(ExprParser::ConcatExprContext * ctx)  { }
  virtual void exitConcatExpr(ExprParser::ConcatExprContext * ctx)  {
    std::string c1d,c2o;
    c1d=desti.get(ctx->expr(0));
    c2o=origen.get(ctx->expr(1));
    if(c1d!=c2o) std::cout<<"ERROR: Concatenació no valida"<<std::endl;
    origen.put(ctx,origen.get(ctx->expr(0)));
    desti.put(ctx,desti.get(ctx->expr(1)));
   }


};
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
  //std::cout << "result with tree props = " << eval2.values.get(tree) << std::endl;


  return EXIT_SUCCESS;
}
