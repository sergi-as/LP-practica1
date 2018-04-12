
// Generated from Expr.g4 by ANTLR 4.7.1


#include "ExprListener.h"

#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SContext ------------------------------------------------------------------

ExprParser::SContext::SContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::RutaContext *> ExprParser::SContext::ruta() {
  return getRuleContexts<ExprParser::RutaContext>();
}

ExprParser::RutaContext* ExprParser::SContext::ruta(size_t i) {
  return getRuleContext<ExprParser::RutaContext>(i);
}


size_t ExprParser::SContext::getRuleIndex() const {
  return ExprParser::RuleS;
}

void ExprParser::SContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterS(this);
}

void ExprParser::SContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitS(this);
}

ExprParser::SContext* ExprParser::s() {
  SContext *_localctx = _tracker.createInstance<SContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleS);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(9);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::ID) {
      setState(6);
      ruta();
      setState(11);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RutaContext ------------------------------------------------------------------

ExprParser::RutaContext::RutaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::RutaContext::getRuleIndex() const {
  return ExprParser::RuleRuta;
}

void ExprParser::RutaContext::copyFrom(RutaContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RutaLitContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> ExprParser::RutaLitContext::ID() {
  return getTokens(ExprParser::ID);
}

tree::TerminalNode* ExprParser::RutaLitContext::ID(size_t i) {
  return getToken(ExprParser::ID, i);
}

tree::TerminalNode* ExprParser::RutaLitContext::ASSIG() {
  return getToken(ExprParser::ASSIG, 0);
}

tree::TerminalNode* ExprParser::RutaLitContext::NUM() {
  return getToken(ExprParser::NUM, 0);
}

ExprParser::RutaLitContext::RutaLitContext(RutaContext *ctx) { copyFrom(ctx); }

void ExprParser::RutaLitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRutaLit(this);
}
void ExprParser::RutaLitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRutaLit(this);
}
//----------------- RutaExprContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::RutaExprContext::ID() {
  return getToken(ExprParser::ID, 0);
}

tree::TerminalNode* ExprParser::RutaExprContext::ASSIG() {
  return getToken(ExprParser::ASSIG, 0);
}

ExprParser::ExprContext* ExprParser::RutaExprContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::RutaExprContext::RutaExprContext(RutaContext *ctx) { copyFrom(ctx); }

void ExprParser::RutaExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRutaExpr(this);
}
void ExprParser::RutaExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRutaExpr(this);
}
ExprParser::RutaContext* ExprParser::ruta() {
  RutaContext *_localctx = _tracker.createInstance<RutaContext>(_ctx, getState());
  enterRule(_localctx, 2, ExprParser::RuleRuta);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(20);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<RutaContext *>(_tracker.createInstance<ExprParser::RutaLitContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(12);
      match(ExprParser::ID);
      setState(13);
      match(ExprParser::ASSIG);
      setState(14);
      match(ExprParser::ID);
      setState(15);
      match(ExprParser::ID);
      setState(16);
      match(ExprParser::NUM);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<RutaContext *>(_tracker.createInstance<ExprParser::RutaExprContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(17);
      match(ExprParser::ID);
      setState(18);
      match(ExprParser::ASSIG);
      setState(19);
      expr(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ExprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParExprContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::ParExprContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::ParExprContext::ParExprContext(ExprContext *ctx) { copyFrom(ctx); }

void ExprParser::ParExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParExpr(this);
}
void ExprParser::ParExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParExpr(this);
}
//----------------- AlterExprContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::AlterExprContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::AlterExprContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

tree::TerminalNode* ExprParser::AlterExprContext::ALTER() {
  return getToken(ExprParser::ALTER, 0);
}

ExprParser::AlterExprContext::AlterExprContext(ExprContext *ctx) { copyFrom(ctx); }

void ExprParser::AlterExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlterExpr(this);
}
void ExprParser::AlterExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlterExpr(this);
}
//----------------- IdExprContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::IdExprContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::IdExprContext::IdExprContext(ExprContext *ctx) { copyFrom(ctx); }

void ExprParser::IdExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdExpr(this);
}
void ExprParser::IdExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdExpr(this);
}
//----------------- ConcatExprContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ConcatExprContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ConcatExprContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

tree::TerminalNode* ExprParser::ConcatExprContext::CONCAT() {
  return getToken(ExprParser::CONCAT, 0);
}

ExprParser::ConcatExprContext::ConcatExprContext(ExprContext *ctx) { copyFrom(ctx); }

void ExprParser::ConcatExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcatExpr(this);
}
void ExprParser::ConcatExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcatExpr(this);
}

ExprParser::ExprContext* ExprParser::expr() {
   return expr(0);
}

ExprParser::ExprContext* ExprParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ExprParser::ExprContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, ExprParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(28);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::T__0: {
        _localctx = _tracker.createInstance<ParExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(23);
        match(ExprParser::T__0);
        setState(24);
        expr(0);
        setState(25);
        match(ExprParser::T__1);
        break;
      }

      case ExprParser::ID: {
        _localctx = _tracker.createInstance<IdExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(27);
        match(ExprParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(38);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(36);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ConcatExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(30);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(31);
          match(ExprParser::CONCAT);
          setState(32);
          expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AlterExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(33);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(34);
          match(ExprParser::ALTER);
          setState(35);
          expr(3);
          break;
        }

        } 
      }
      setState(40);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "s", "ruta", "expr"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'('", "')'", "':='", "'+'", "'|'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "ASSIG", "CONCAT", "ALTER", "NUM", "ID", "WS"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xa, 0x2c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x3, 0x2, 0x7, 0x2, 0xa, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xd, 0xb, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x17, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x1f, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x27, 0xa, 0x4, 
    0xc, 0x4, 0xe, 0x4, 0x2a, 0xb, 0x4, 0x3, 0x4, 0x2, 0x3, 0x6, 0x5, 0x2, 
    0x4, 0x6, 0x2, 0x2, 0x2, 0x2d, 0x2, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4, 0x16, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x8, 0xa, 0x5, 0x4, 
    0x3, 0x2, 0x9, 0x8, 0x3, 0x2, 0x2, 0x2, 0xa, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0xb, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0xd, 0xb, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf, 0x7, 0x9, 
    0x2, 0x2, 0xf, 0x10, 0x7, 0x5, 0x2, 0x2, 0x10, 0x11, 0x7, 0x9, 0x2, 
    0x2, 0x11, 0x12, 0x7, 0x9, 0x2, 0x2, 0x12, 0x17, 0x7, 0x8, 0x2, 0x2, 
    0x13, 0x14, 0x7, 0x9, 0x2, 0x2, 0x14, 0x15, 0x7, 0x5, 0x2, 0x2, 0x15, 
    0x17, 0x5, 0x6, 0x4, 0x2, 0x16, 0xe, 0x3, 0x2, 0x2, 0x2, 0x16, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x17, 0x5, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x8, 
    0x4, 0x1, 0x2, 0x19, 0x1a, 0x7, 0x3, 0x2, 0x2, 0x1a, 0x1b, 0x5, 0x6, 
    0x4, 0x2, 0x1b, 0x1c, 0x7, 0x4, 0x2, 0x2, 0x1c, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x1d, 0x1f, 0x7, 0x9, 0x2, 0x2, 0x1e, 0x18, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x28, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x21, 0xc, 0x5, 0x2, 0x2, 0x21, 0x22, 0x7, 0x6, 0x2, 0x2, 0x22, 0x27, 
    0x5, 0x6, 0x4, 0x6, 0x23, 0x24, 0xc, 0x4, 0x2, 0x2, 0x24, 0x25, 0x7, 
    0x7, 0x2, 0x2, 0x25, 0x27, 0x5, 0x6, 0x4, 0x5, 0x26, 0x20, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x23, 0x3, 0x2, 0x2, 0x2, 0x27, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x29, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x7, 
    0xb, 0x16, 0x1e, 0x26, 0x28, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
