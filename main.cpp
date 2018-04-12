
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
// Sample "calculator" (special case of collector)
/*
class Evaluator : public ExprBaseListener {
public:

  std::stack<int> stack;

  void exitProd(ExprParser::ProdContext *ctx) {
    int right = stack.top();
    stack.pop();
    int left = stack.top();
    stack.pop();
    stack.push(left*right);
  }

  void exitPlus(ExprParser::PlusContext *ctx) {
    int right = stack.top();
    stack.pop();
    int left = stack.top();
    stack.pop();
    stack.push(left+right);
  }

  void exitValue(ExprParser::ValueContext *ctx) {
    int val = std::stoi(ctx->getText());
    stack.push(val);
  }

};
*/
// Sample "calculator" (special case of collector)
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// Sample "calculator" using tree properties not stack
class EvaluatorWithProps : public ExprBaseListener {
public:

  antlr4::tree::ParseTreeProperty<int> values;
  antlr4::tree::ParseTreeProperty<bool> bval;
  antlr4::tree::ParseTreeProperty<std::string> type;

  void exitS(ExprParser::SContext *ctx) {
    std::string t=type.get(ctx->cmp());
    type.put(ctx,t);
    if (t=="int")
      values.put(ctx,values.get(ctx->cmp()));
    else if (t=="bool")
      bval.put(ctx,bval.get(ctx->cmp()));


  }
  void exitOper(ExprParser::OperContext *ctx) {
    values.put(ctx,values.get(ctx->e()));
    type.put(ctx,"int");
  }
  void exitCompar(ExprParser::ComparContext *ctx) {
    int left = values.get(ctx->e(0));
    int right = values.get(ctx->e(1));
    type.put(ctx,"bool");
    if (ctx->bop->getType() == ExprParser::EQ){
        bval.put(ctx,left == right);
    }
    else if (ctx->bop->getType() == ExprParser::LT){
        bval.put(ctx,left<right);
    }
    else if (ctx->bop->getType() == ExprParser::GT){
        bval.put(ctx,left>right);
    }
    else if (ctx->bop->getType() == ExprParser::LE){
        bval.put(ctx,left<=right);
    }
    else{
        bval.put(ctx,left>=right);
    }
  }

  void exitPar(ExprParser::ParContext *ctx) {
    int val=values.get(ctx->e());
    values.put(ctx,val);
  }

  void exitProd(ExprParser::ProdContext *ctx) {
    int left = values.get(ctx->e(0));
    int right = values.get(ctx->e(1));
    if (ctx->op->getType() == ExprParser::MULT){
        values.put(ctx, left*right);
    }
    else{
        values.put(ctx, left/right);
    }
  }

  void exitPlus(ExprParser::PlusContext *ctx) {
    int left = values.get(ctx->e(0));
    int right = values.get(ctx->e(1));

    switch(ctx->op->getType()){
        case ExprParser::ADD:
            values.put(ctx, left+right);
            break;
        case ExprParser::SUB:
            values.put(ctx, left-right);
            break;
    }

  }

  void exitValue(ExprParser::ValueContext *ctx) {
    int val = std::stoi(ctx->getText());
    values.put(ctx, val); // an INT
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

  // Create a first listener (with stack) that will evaluate the expression
  // Evaluator eval;

  // Traverse the tree using this Evaluator
  //walker.walk(&eval, tree);

  // Dump the result (on top of the stack)
  //std::cout << "result = " << eval.stack.top() << std::endl;

  // Create a second listener (with Properties) that will evaluate the expression
  EvaluatorWithProps eval2;

  // Traverse the tree using this EvaluatorWithProps
  walker.walk(&eval2, tree);

  // Dump the result (accessing the root node property)
  if(eval2.type.get(tree)=="int")
    std::cout<<"Result of the operation: "<<eval2.values.get(tree) << std::endl;
  else if(eval2.type.get(tree)=="bool")
    std::cout<<"Result of the comparison "<<eval2.bval.get(tree) << std::endl;

  return EXIT_SUCCESS;
}
