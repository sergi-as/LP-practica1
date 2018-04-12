
// Generated from Expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ExprParser.
 */
class  ExprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterS(ExprParser::SContext *ctx) = 0;
  virtual void exitS(ExprParser::SContext *ctx) = 0;

  virtual void enterRutaLit(ExprParser::RutaLitContext *ctx) = 0;
  virtual void exitRutaLit(ExprParser::RutaLitContext *ctx) = 0;

  virtual void enterRutaExpr(ExprParser::RutaExprContext *ctx) = 0;
  virtual void exitRutaExpr(ExprParser::RutaExprContext *ctx) = 0;

  virtual void enterParExpr(ExprParser::ParExprContext *ctx) = 0;
  virtual void exitParExpr(ExprParser::ParExprContext *ctx) = 0;

  virtual void enterAlterExpr(ExprParser::AlterExprContext *ctx) = 0;
  virtual void exitAlterExpr(ExprParser::AlterExprContext *ctx) = 0;

  virtual void enterIdExpr(ExprParser::IdExprContext *ctx) = 0;
  virtual void exitIdExpr(ExprParser::IdExprContext *ctx) = 0;

  virtual void enterConcatExpr(ExprParser::ConcatExprContext *ctx) = 0;
  virtual void exitConcatExpr(ExprParser::ConcatExprContext *ctx) = 0;


};

