
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

  virtual void enterModules(ExprParser::ModulesContext * /*ctx*/) override { }
  virtual void exitModules(ExprParser::ModulesContext * /*ctx*/) override { }

  virtual void enterDeclarations(ExprParser::DeclarationsContext * /*ctx*/) override { }
  virtual void exitDeclarations(ExprParser::DeclarationsContext * /*ctx*/) override { }

  virtual void enterTy(ExprParser::TyContext * /*ctx*/) override { }
  virtual void exitTy(ExprParser::TyContext * /*ctx*/) override { }

  virtual void enterAssig(ExprParser::AssigContext * /*ctx*/) override { }
  virtual void exitAssig(ExprParser::AssigContext * /*ctx*/) override { }

  virtual void enterModdef(ExprParser::ModdefContext * /*ctx*/) override { }
  virtual void exitModdef(ExprParser::ModdefContext * /*ctx*/) override { }

  virtual void enterWiredef(ExprParser::WiredefContext * /*ctx*/) override { }
  virtual void exitWiredef(ExprParser::WiredefContext * /*ctx*/) override { }

  virtual void enterExpr(ExprParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(ExprParser::ExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

