
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

std::vector<ExprParser::ModulesContext *> ExprParser::SContext::modules() {
  return getRuleContexts<ExprParser::ModulesContext>();
}

ExprParser::ModulesContext* ExprParser::SContext::modules(size_t i) {
  return getRuleContext<ExprParser::ModulesContext>(i);
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
    setState(15);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::MOD) {
      setState(12);
      modules();
      setState(17);
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

//----------------- ModulesContext ------------------------------------------------------------------

ExprParser::ModulesContext::ModulesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ModulesContext::MOD() {
  return getToken(ExprParser::MOD, 0);
}

tree::TerminalNode* ExprParser::ModulesContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::DeclarationsContext* ExprParser::ModulesContext::declarations() {
  return getRuleContext<ExprParser::DeclarationsContext>(0);
}

tree::TerminalNode* ExprParser::ModulesContext::END() {
  return getToken(ExprParser::END, 0);
}

std::vector<ExprParser::DefinitionsContext *> ExprParser::ModulesContext::definitions() {
  return getRuleContexts<ExprParser::DefinitionsContext>();
}

ExprParser::DefinitionsContext* ExprParser::ModulesContext::definitions(size_t i) {
  return getRuleContext<ExprParser::DefinitionsContext>(i);
}


size_t ExprParser::ModulesContext::getRuleIndex() const {
  return ExprParser::RuleModules;
}

void ExprParser::ModulesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModules(this);
}

void ExprParser::ModulesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModules(this);
}

ExprParser::ModulesContext* ExprParser::modules() {
  ModulesContext *_localctx = _tracker.createInstance<ModulesContext>(_ctx, getState());
  enterRule(_localctx, 2, ExprParser::RuleModules);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    match(ExprParser::MOD);
    setState(19);
    match(ExprParser::ID);
    setState(20);
    declarations();
    setState(22); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(21);
      definitions();
      setState(24); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ExprParser::WIRE

    || _la == ExprParser::ID);
    setState(26);
    match(ExprParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

ExprParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::TyContext *> ExprParser::DeclarationsContext::ty() {
  return getRuleContexts<ExprParser::TyContext>();
}

ExprParser::TyContext* ExprParser::DeclarationsContext::ty(size_t i) {
  return getRuleContext<ExprParser::TyContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::DeclarationsContext::ID() {
  return getTokens(ExprParser::ID);
}

tree::TerminalNode* ExprParser::DeclarationsContext::ID(size_t i) {
  return getToken(ExprParser::ID, i);
}


size_t ExprParser::DeclarationsContext::getRuleIndex() const {
  return ExprParser::RuleDeclarations;
}

void ExprParser::DeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarations(this);
}

void ExprParser::DeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarations(this);
}

ExprParser::DeclarationsContext* ExprParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 4, ExprParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    match(ExprParser::T__0);
    setState(29);
    ty();
    setState(30);
    match(ExprParser::ID);
    setState(37);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__1) {
      setState(31);
      match(ExprParser::T__1);
      setState(32);
      ty();
      setState(33);
      match(ExprParser::ID);
      setState(39);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(40);
    match(ExprParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TyContext ------------------------------------------------------------------

ExprParser::TyContext::TyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::TyContext::IN() {
  return getToken(ExprParser::IN, 0);
}

tree::TerminalNode* ExprParser::TyContext::OUT() {
  return getToken(ExprParser::OUT, 0);
}


size_t ExprParser::TyContext::getRuleIndex() const {
  return ExprParser::RuleTy;
}

void ExprParser::TyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTy(this);
}

void ExprParser::TyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTy(this);
}

ExprParser::TyContext* ExprParser::ty() {
  TyContext *_localctx = _tracker.createInstance<TyContext>(_ctx, getState());
  enterRule(_localctx, 6, ExprParser::RuleTy);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    _la = _input->LA(1);
    if (!(_la == ExprParser::IN

    || _la == ExprParser::OUT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionsContext ------------------------------------------------------------------

ExprParser::DefinitionsContext::DefinitionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::DefinitionsContext::getRuleIndex() const {
  return ExprParser::RuleDefinitions;
}

void ExprParser::DefinitionsContext::copyFrom(DefinitionsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AssigContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::AssigContext::ID() {
  return getToken(ExprParser::ID, 0);
}

tree::TerminalNode* ExprParser::AssigContext::EQ() {
  return getToken(ExprParser::EQ, 0);
}

ExprParser::ExprContext* ExprParser::AssigContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::AssigContext::AssigContext(DefinitionsContext *ctx) { copyFrom(ctx); }

void ExprParser::AssigContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssig(this);
}
void ExprParser::AssigContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssig(this);
}
//----------------- ModdefContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> ExprParser::ModdefContext::ID() {
  return getTokens(ExprParser::ID);
}

tree::TerminalNode* ExprParser::ModdefContext::ID(size_t i) {
  return getToken(ExprParser::ID, i);
}

ExprParser::ModdefContext::ModdefContext(DefinitionsContext *ctx) { copyFrom(ctx); }

void ExprParser::ModdefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModdef(this);
}
void ExprParser::ModdefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModdef(this);
}
//----------------- WiredefContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::WiredefContext::WIRE() {
  return getToken(ExprParser::WIRE, 0);
}

std::vector<tree::TerminalNode *> ExprParser::WiredefContext::ID() {
  return getTokens(ExprParser::ID);
}

tree::TerminalNode* ExprParser::WiredefContext::ID(size_t i) {
  return getToken(ExprParser::ID, i);
}

ExprParser::WiredefContext::WiredefContext(DefinitionsContext *ctx) { copyFrom(ctx); }

void ExprParser::WiredefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWiredef(this);
}
void ExprParser::WiredefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWiredef(this);
}
ExprParser::DefinitionsContext* ExprParser::definitions() {
  DefinitionsContext *_localctx = _tracker.createInstance<DefinitionsContext>(_ctx, getState());
  enterRule(_localctx, 8, ExprParser::RuleDefinitions);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(71);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DefinitionsContext *>(_tracker.createInstance<ExprParser::AssigContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(44);
      match(ExprParser::ID);
      setState(45);
      match(ExprParser::EQ);
      setState(46);
      expr(0);
      setState(47);
      match(ExprParser::T__3);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DefinitionsContext *>(_tracker.createInstance<ExprParser::ModdefContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(49);
      match(ExprParser::ID);
      setState(50);
      match(ExprParser::T__0);
      setState(51);
      match(ExprParser::ID);
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ExprParser::T__1) {
        setState(52);
        match(ExprParser::T__1);
        setState(53);
        match(ExprParser::ID);
        setState(58);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(59);
      match(ExprParser::T__2);
      setState(60);
      match(ExprParser::T__3);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<DefinitionsContext *>(_tracker.createInstance<ExprParser::WiredefContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(61);
      match(ExprParser::WIRE);
      setState(62);
      match(ExprParser::ID);
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ExprParser::T__1) {
        setState(63);
        match(ExprParser::T__1);
        setState(64);
        match(ExprParser::ID);
        setState(69);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(70);
      match(ExprParser::T__3);
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

tree::TerminalNode* ExprParser::ExprContext::NOT() {
  return getToken(ExprParser::NOT, 0);
}

tree::TerminalNode* ExprParser::ExprContext::ID() {
  return getToken(ExprParser::ID, 0);
}

std::vector<ExprParser::ExprContext *> ExprParser::ExprContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

tree::TerminalNode* ExprParser::ExprContext::AND() {
  return getToken(ExprParser::AND, 0);
}

tree::TerminalNode* ExprParser::ExprContext::OR() {
  return getToken(ExprParser::OR, 0);
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ExprParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


ExprParser::ExprContext* ExprParser::expr() {
   return expr(0);
}

ExprParser::ExprContext* ExprParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ExprParser::ExprContext *previousContext = _localctx;
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, ExprParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(77);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::NOT: {
        setState(74);
        match(ExprParser::NOT);
        setState(75);
        match(ExprParser::ID);
        break;
      }

      case ExprParser::ID: {
        setState(76);
        match(ExprParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(87);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(85);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(79);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(80);
          match(ExprParser::AND);
          setState(81);
          expr(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(82);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(83);
          match(ExprParser::OR);
          setState(84);
          expr(3);
          break;
        }

        } 
      }
      setState(89);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
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
    case 5: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

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
  "s", "modules", "declarations", "ty", "definitions", "expr"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'('", "','", "')'", "';'", "'module'", "'endmodule'", "'input'", 
  "'output'", "'wire'", "'or'", "'and'", "'not'", "'='"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "MOD", "END", "IN", "OUT", "WIRE", "OR", "AND", "NOT", 
  "EQ", "ID", "WS"
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
    0x3, 0x11, 0x5d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x7, 0x2, 0x10, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x13, 0xb, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x6, 0x3, 0x19, 0xa, 0x3, 0xd, 0x3, 
    0xe, 0x3, 0x1a, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x26, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x29, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x39, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0x3c, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x7, 0x6, 0x44, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x47, 0xb, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x4a, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0x50, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x7, 0x7, 0x58, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x5b, 0xb, 
    0x7, 0x3, 0x7, 0x2, 0x3, 0xc, 0x8, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0x2, 
    0x3, 0x3, 0x2, 0x9, 0xa, 0x2, 0x60, 0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x49, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x10, 0x5, 0x4, 0x3, 0x2, 0xf, 0xe, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x13, 0x3, 0x2, 0x2, 0x2, 0x11, 0xf, 0x3, 0x2, 0x2, 0x2, 0x11, 
    0x12, 0x3, 0x2, 0x2, 0x2, 0x12, 0x3, 0x3, 0x2, 0x2, 0x2, 0x13, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x7, 0x7, 0x2, 0x2, 0x15, 0x16, 0x7, 
    0x10, 0x2, 0x2, 0x16, 0x18, 0x5, 0x6, 0x4, 0x2, 0x17, 0x19, 0x5, 0xa, 
    0x6, 0x2, 0x18, 0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x7, 0x8, 0x2, 0x2, 0x1d, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0x3, 0x2, 0x2, 0x1f, 0x20, 
    0x5, 0x8, 0x5, 0x2, 0x20, 0x27, 0x7, 0x10, 0x2, 0x2, 0x21, 0x22, 0x7, 
    0x4, 0x2, 0x2, 0x22, 0x23, 0x5, 0x8, 0x5, 0x2, 0x23, 0x24, 0x7, 0x10, 
    0x2, 0x2, 0x24, 0x26, 0x3, 0x2, 0x2, 0x2, 0x25, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x29, 0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x29, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x5, 0x2, 0x2, 0x2b, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x9, 0x2, 0x2, 0x2, 0x2d, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x10, 0x2, 0x2, 0x2f, 0x30, 0x7, 0xf, 
    0x2, 0x2, 0x30, 0x31, 0x5, 0xc, 0x7, 0x2, 0x31, 0x32, 0x7, 0x6, 0x2, 
    0x2, 0x32, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x10, 0x2, 0x2, 
    0x34, 0x35, 0x7, 0x3, 0x2, 0x2, 0x35, 0x3a, 0x7, 0x10, 0x2, 0x2, 0x36, 
    0x37, 0x7, 0x4, 0x2, 0x2, 0x37, 0x39, 0x7, 0x10, 0x2, 0x2, 0x38, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x5, 0x2, 
    0x2, 0x3e, 0x4a, 0x7, 0x6, 0x2, 0x2, 0x3f, 0x40, 0x7, 0xb, 0x2, 0x2, 
    0x40, 0x45, 0x7, 0x10, 0x2, 0x2, 0x41, 0x42, 0x7, 0x4, 0x2, 0x2, 0x42, 
    0x44, 0x7, 0x10, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x44, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x48, 0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x4a, 0x7, 0x6, 0x2, 0x2, 0x49, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x33, 0x3, 0x2, 0x2, 0x2, 0x49, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x8, 0x7, 0x1, 0x2, 0x4c, 
    0x4d, 0x7, 0xe, 0x2, 0x2, 0x4d, 0x50, 0x7, 0x10, 0x2, 0x2, 0x4e, 0x50, 
    0x7, 0x10, 0x2, 0x2, 0x4f, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4e, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x59, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0xc, 0x5, 
    0x2, 0x2, 0x52, 0x53, 0x7, 0xd, 0x2, 0x2, 0x53, 0x58, 0x5, 0xc, 0x7, 
    0x6, 0x54, 0x55, 0xc, 0x4, 0x2, 0x2, 0x55, 0x56, 0x7, 0xc, 0x2, 0x2, 
    0x56, 0x58, 0x5, 0xc, 0x7, 0x5, 0x57, 0x51, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x54, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0xb, 0x11, 0x1a, 0x27, 
    0x3a, 0x45, 0x49, 0x4f, 0x57, 0x59, 
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
