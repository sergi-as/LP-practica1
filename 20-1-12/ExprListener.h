
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

  virtual void enterModules(ExprParser::ModulesContext *ctx) = 0;
  virtual void exitModules(ExprParser::ModulesContext *ctx) = 0;

  virtual void enterDeclarations(ExprParser::DeclarationsContext *ctx) = 0;
  virtual void exitDeclarations(ExprParser::DeclarationsContext *ctx) = 0;

  virtual void enterTy(ExprParser::TyContext *ctx) = 0;
  virtual void exitTy(ExprParser::TyContext *ctx) = 0;

  virtual void enterAssig(ExprParser::AssigContext *ctx) = 0;
  virtual void exitAssig(ExprParser::AssigContext *ctx) = 0;

  virtual void enterModdef(ExprParser::ModdefContext *ctx) = 0;
  virtual void exitModdef(ExprParser::ModdefContext *ctx) = 0;

  virtual void enterWiredef(ExprParser::WiredefContext *ctx) = 0;
  virtual void exitWiredef(ExprParser::WiredefContext *ctx) = 0;

  virtual void enterExpr(ExprParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ExprParser::ExprContext *ctx) = 0;


};

