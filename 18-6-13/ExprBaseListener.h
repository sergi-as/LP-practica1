
// Generated from Expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "ExprListener.h"


/**
 * This class provides an empty implementation of ExprListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ExprBaseListener : public ExprListener {
public:

  virtual void enterS(ExprParser::SContext * /*ctx*/) override { }
  virtual void exitS(ExprParser::SContext * /*ctx*/) override { }

  virtual void enterRutaLit(ExprParser::RutaLitContext * /*ctx*/) override { }
  virtual void exitRutaLit(ExprParser::RutaLitContext * /*ctx*/) override { }

  virtual void enterRutaExpr(ExprParser::RutaExprContext * /*ctx*/) override { }
  virtual void exitRutaExpr(ExprParser::RutaExprContext * /*ctx*/) override { }

  virtual void enterParExpr(ExprParser::ParExprContext * /*ctx*/) override { }
  virtual void exitParExpr(ExprParser::ParExprContext * /*ctx*/) override { }

  virtual void enterAlterExpr(ExprParser::AlterExprContext * /*ctx*/) override { }
  virtual void exitAlterExpr(ExprParser::AlterExprContext * /*ctx*/) override { }

  virtual void enterIdExpr(ExprParser::IdExprContext * /*ctx*/) override { }
  virtual void exitIdExpr(ExprParser::IdExprContext * /*ctx*/) override { }

  virtual void enterConcatExpr(ExprParser::ConcatExprContext * /*ctx*/) override { }
  virtual void exitConcatExpr(ExprParser::ConcatExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

