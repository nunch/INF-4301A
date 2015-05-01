// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.
// //                    "%code top" blocks.
#line 24 "parsecalc.yy" // lalr1.cc:392

  #include "Exp.hh"
  #include <stdio.h>
  #include <stdlib.h>
  #include <map>
  #include <vector>
  #include "scancalc.cc"
  
  Ressources vars;
  Ressources* Engine::vars2 = &vars;
  Ressources* Calculator::vars2 = &vars;
  Engine engine;

  int LetExp::totalNum = -1;

  bool isInHead = false;
  bool isInBody = true;
  bool isNewScope = false;
  bool isInFunction = false;
  bool isInClass = false;
  std::vector<Sequence*> vector;
  FILE* in = NULL;
  int isInside = 0;
  FILE* truc = stdin;

#line 60 "parsecalc.cc" // lalr1.cc:392


// First part of user declarations.

#line 65 "parsecalc.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parsecalc.hh"

// User implementation prologue.

#line 79 "parsecalc.cc" // lalr1.cc:407


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 165 "parsecalc.cc" // lalr1.cc:474

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (unsigned* nerrs_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      nerrs (nerrs_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 37: // line
      case 38: // exp
        value.copy< Exp* > (other.value);
        break;

      case 39: // exps
        value.copy< Sequence* > (other.value);
        break;

      case 6: // FILENAME
        value.copy< char* > (other.value);
        break;

      case 3: // INT
        value.copy< int > (other.value);
        break;

      case 4: // STRING
      case 5: // STDSTRING
      case 7: // "function"
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 37: // line
      case 38: // exp
        value.copy< Exp* > (v);
        break;

      case 39: // exps
        value.copy< Sequence* > (v);
        break;

      case 6: // FILENAME
        value.copy< char* > (v);
        break;

      case 3: // INT
        value.copy< int > (v);
        break;

      case 4: // STRING
      case 5: // STDSTRING
      case 7: // "function"
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Exp* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Sequence* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const char* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 37: // line
      case 38: // exp
        value.template destroy< Exp* > ();
        break;

      case 39: // exps
        value.template destroy< Sequence* > ();
        break;

      case 6: // FILENAME
        value.template destroy< char* > ();
        break;

      case 3: // INT
        value.template destroy< int > ();
        break;

      case 4: // STRING
      case 5: // STDSTRING
      case 7: // "function"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 37: // line
      case 38: // exp
        value.move< Exp* > (s.value);
        break;

      case 39: // exps
        value.move< Sequence* > (s.value);
        break;

      case 6: // FILENAME
        value.move< char* > (s.value);
        break;

      case 3: // INT
        value.move< int > (s.value);
        break;

      case 4: // STRING
      case 5: // STDSTRING
      case 7: // "function"
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_EOF (const location_type& l)
  {
    return symbol_type (token::TOK_EOF, l);
  }

  parser::symbol_type
  parser::make_INT (const int& v, const location_type& l)
  {
    return symbol_type (token::TOK_INT, v, l);
  }

  parser::symbol_type
  parser::make_STRING (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_STRING, v, l);
  }

  parser::symbol_type
  parser::make_STDSTRING (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_STDSTRING, v, l);
  }

  parser::symbol_type
  parser::make_FILENAME (const char*& v, const location_type& l)
  {
    return symbol_type (token::TOK_FILENAME, v, l);
  }

  parser::symbol_type
  parser::make_FUNCTION (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_FUNCTION, v, l);
  }

  parser::symbol_type
  parser::make_LPAREN (const location_type& l)
  {
    return symbol_type (token::TOK_LPAREN, l);
  }

  parser::symbol_type
  parser::make_MINUS (const location_type& l)
  {
    return symbol_type (token::TOK_MINUS, l);
  }

  parser::symbol_type
  parser::make_PLUS (const location_type& l)
  {
    return symbol_type (token::TOK_PLUS, l);
  }

  parser::symbol_type
  parser::make_RPAREN (const location_type& l)
  {
    return symbol_type (token::TOK_RPAREN, l);
  }

  parser::symbol_type
  parser::make_SLASH (const location_type& l)
  {
    return symbol_type (token::TOK_SLASH, l);
  }

  parser::symbol_type
  parser::make_STAR (const location_type& l)
  {
    return symbol_type (token::TOK_STAR, l);
  }

  parser::symbol_type
  parser::make_PV (const location_type& l)
  {
    return symbol_type (token::TOK_PV, l);
  }

  parser::symbol_type
  parser::make_EOL (const location_type& l)
  {
    return symbol_type (token::TOK_EOL, l);
  }

  parser::symbol_type
  parser::make_IF (const location_type& l)
  {
    return symbol_type (token::TOK_IF, l);
  }

  parser::symbol_type
  parser::make_ELSE (const location_type& l)
  {
    return symbol_type (token::TOK_ELSE, l);
  }

  parser::symbol_type
  parser::make_FOR (const location_type& l)
  {
    return symbol_type (token::TOK_FOR, l);
  }

  parser::symbol_type
  parser::make_FROM (const location_type& l)
  {
    return symbol_type (token::TOK_FROM, l);
  }

  parser::symbol_type
  parser::make_TO (const location_type& l)
  {
    return symbol_type (token::TOK_TO, l);
  }

  parser::symbol_type
  parser::make_DO (const location_type& l)
  {
    return symbol_type (token::TOK_DO, l);
  }

  parser::symbol_type
  parser::make_WHILE (const location_type& l)
  {
    return symbol_type (token::TOK_WHILE, l);
  }

  parser::symbol_type
  parser::make_LACO (const location_type& l)
  {
    return symbol_type (token::TOK_LACO, l);
  }

  parser::symbol_type
  parser::make_RACO (const location_type& l)
  {
    return symbol_type (token::TOK_RACO, l);
  }

  parser::symbol_type
  parser::make_THEN (const location_type& l)
  {
    return symbol_type (token::TOK_THEN, l);
  }

  parser::symbol_type
  parser::make_VAR (const location_type& l)
  {
    return symbol_type (token::TOK_VAR, l);
  }

  parser::symbol_type
  parser::make_EQUALS (const location_type& l)
  {
    return symbol_type (token::TOK_EQUALS, l);
  }

  parser::symbol_type
  parser::make_AFFICHE (const location_type& l)
  {
    return symbol_type (token::TOK_AFFICHE, l);
  }

  parser::symbol_type
  parser::make_LET (const location_type& l)
  {
    return symbol_type (token::TOK_LET, l);
  }

  parser::symbol_type
  parser::make_IN (const location_type& l)
  {
    return symbol_type (token::TOK_IN, l);
  }

  parser::symbol_type
  parser::make_END (const location_type& l)
  {
    return symbol_type (token::TOK_END, l);
  }

  parser::symbol_type
  parser::make_VIR (const location_type& l)
  {
    return symbol_type (token::TOK_VIR, l);
  }

  parser::symbol_type
  parser::make_IMPORT (const location_type& l)
  {
    return symbol_type (token::TOK_IMPORT, l);
  }

  parser::symbol_type
  parser::make_CLASS (const location_type& l)
  {
    return symbol_type (token::TOK_CLASS, l);
  }



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 37: // line
      case 38: // exp
        value.move< Exp* > (that.value);
        break;

      case 39: // exps
        value.move< Sequence* > (that.value);
        break;

      case 6: // FILENAME
        value.move< char* > (that.value);
        break;

      case 3: // INT
        value.move< int > (that.value);
        break;

      case 4: // STRING
      case 5: // STDSTRING
      case 7: // "function"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 37: // line
      case 38: // exp
        value.copy< Exp* > (that.value);
        break;

      case 39: // exps
        value.copy< Sequence* > (that.value);
        break;

      case 6: // FILENAME
        value.copy< char* > (that.value);
        break;

      case 3: // INT
        value.copy< int > (that.value);
        break;

      case 4: // STRING
      case 5: // STDSTRING
      case 7: // "function"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 37: // line

#line 63 "parsecalc.yy" // lalr1.cc:617
        { yyo << yysym.value.template as< Exp* > (); }
#line 811 "parsecalc.cc" // lalr1.cc:617
        break;

      case 38: // exp

#line 63 "parsecalc.yy" // lalr1.cc:617
        { yyo << yysym.value.template as< Exp* > (); }
#line 818 "parsecalc.cc" // lalr1.cc:617
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 37: // line
      case 38: // exp
        yylhs.value.build< Exp* > ();
        break;

      case 39: // exps
        yylhs.value.build< Sequence* > ();
        break;

      case 6: // FILENAME
        yylhs.value.build< char* > ();
        break;

      case 3: // INT
        yylhs.value.build< int > ();
        break;

      case 4: // STRING
      case 5: // STDSTRING
      case 7: // "function"
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 3:
#line 109 "parsecalc.yy" // lalr1.cc:847
    { 

                std::stringstream ss;
                std::string s;
                ss<<*yystack_[0].value.as< Exp* > ();
                s = ss.str();
                if(s!="null"){
                  std::cout<<*yystack_[0].value.as< Exp* > ()<<std::endl;
                  //vars.newExp($2);
                  if(isNewScope){
                    if(isInside>0){
                      if(isInBody) vars.addExpInBody(yystack_[0].value.as< Exp* > ());
                      if(isInHead) vars.addExpInHead(yystack_[0].value.as< Exp* > ());
                    }else{
                      vars.addExpInGeneralScope(yystack_[0].value.as< Exp* > ());
                    }
                  }
                  if(isNewScope) isInside++;
                  isNewScope=false;
                  yystack_[0].value.as< Exp* > ()->accept(engine);
                }
              }
#line 1088 "parsecalc.cc" // lalr1.cc:847
    break;

  case 4:
#line 134 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = yylhs.value.as< Exp* > ()=new Null(); }
#line 1094 "parsecalc.cc" // lalr1.cc:847
    break;

  case 5:
#line 135 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = yystack_[1].value.as< Exp* > (); }
#line 1100 "parsecalc.cc" // lalr1.cc:847
    break;

  case 6:
#line 136 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = yylhs.value.as< Exp* > ()=new Null(); yyerrok; }
#line 1106 "parsecalc.cc" // lalr1.cc:847
    break;

  case 7:
#line 142 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createBin('+',yystack_[2].value.as< Exp* > (), yystack_[0].value.as< Exp* > ()); }
#line 1112 "parsecalc.cc" // lalr1.cc:847
    break;

  case 8:
#line 143 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createBin('-',yystack_[2].value.as< Exp* > (), yystack_[0].value.as< Exp* > ()); }
#line 1118 "parsecalc.cc" // lalr1.cc:847
    break;

  case 9:
#line 144 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createBin('*',yystack_[2].value.as< Exp* > (), yystack_[0].value.as< Exp* > ()); }
#line 1124 "parsecalc.cc" // lalr1.cc:847
    break;

  case 10:
#line 145 "parsecalc.yy" // lalr1.cc:847
    {  
                  Engine calc;
                  double i=(*yystack_[0].value.as< Exp* > ())();
                  if(i){
                    yylhs.value.as< Exp* > () = createBin('/',yystack_[2].value.as< Exp* > (), yystack_[0].value.as< Exp* > ()); 
                  }else{
                    error(yystack_[0].location, "division by 0");
                    YYERROR;
                  }
}
#line 1139 "parsecalc.cc" // lalr1.cc:847
    break;

  case 11:
#line 155 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = yystack_[1].value.as< Sequence* > (); }
#line 1145 "parsecalc.cc" // lalr1.cc:847
    break;

  case 12:
#line 156 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createNum(777); }
#line 1151 "parsecalc.cc" // lalr1.cc:847
    break;

  case 13:
#line 157 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createNum(yystack_[0].value.as< int > ()); }
#line 1157 "parsecalc.cc" // lalr1.cc:847
    break;

  case 14:
#line 158 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createIf(yystack_[4].value.as< Exp* > (),yystack_[2].value.as< Exp* > (),yystack_[0].value.as< Exp* > ());}
#line 1163 "parsecalc.cc" // lalr1.cc:847
    break;

  case 15:
#line 159 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createIf(yystack_[2].value.as< Exp* > (),yystack_[0].value.as< Exp* > ());}
#line 1169 "parsecalc.cc" // lalr1.cc:847
    break;

  case 16:
#line 160 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createFor(yystack_[4].value.as< Exp* > (),yystack_[2].value.as< Exp* > (),yystack_[2].value.as< Exp* > (),yystack_[0].value.as< Exp* > ());vars.newVar(((Var*) yystack_[4].value.as< Exp* > ())->name_, yystack_[4].value.as< Exp* > ());}
#line 1175 "parsecalc.cc" // lalr1.cc:847
    break;

  case 17:
#line 161 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createWhile(yystack_[2].value.as< Exp* > (),yystack_[0].value.as< Exp* > ());}
#line 1181 "parsecalc.cc" // lalr1.cc:847
    break;

  case 18:
#line 162 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > ()=new Null(); }
#line 1187 "parsecalc.cc" // lalr1.cc:847
    break;

  case 19:
#line 163 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > ()=new Null(); }
#line 1193 "parsecalc.cc" // lalr1.cc:847
    break;

  case 20:
#line 164 "parsecalc.yy" // lalr1.cc:847
    {
  yylhs.value.as< Exp* > () = new Null();
  freopen(yystack_[0].value.as< char* > (),"r",stdin);
}
#line 1202 "parsecalc.cc" // lalr1.cc:847
    break;

  case 21:
#line 168 "parsecalc.yy" // lalr1.cc:847
    {
 try{
    //vars.newVar($2,$4); 
    yylhs.value.as< Exp* > ()=createVar(yystack_[2].value.as< std::string > (),yystack_[0].value.as< Exp* > ());
  }catch(const std::string& msg){
    error(yystack_[2].location,msg);YYERROR;
  }
}
#line 1215 "parsecalc.cc" // lalr1.cc:847
    break;

  case 22:
#line 176 "parsecalc.yy" // lalr1.cc:847
    {
  bool res = vars.hasVar(yystack_[2].value.as< std::string > ());
  try{
    if(res){
      //vars.setVar($1,$3);
      yylhs.value.as< Exp* > () = new Assignment(yystack_[2].value.as< std::string > (),yystack_[0].value.as< Exp* > ());
    }else{
      error(yystack_[2].location, "is not an existed variable"); YYERROR;
    }
  }catch(const std::string & Msg){
    error(yystack_[2].location, "truc de merde"); YYERROR;
  }
}
#line 1233 "parsecalc.cc" // lalr1.cc:847
    break;

  case 23:
#line 189 "parsecalc.yy" // lalr1.cc:847
    { 
            try{
              yylhs.value.as< Exp* > () = new ShowVar(yystack_[0].value.as< std::string > (),vars.getVar(yystack_[0].value.as< std::string > ()));
            } catch(const std::string & Msg){
              error(yystack_[0].location, "not a statement"); YYERROR;
            }
}
#line 1245 "parsecalc.cc" // lalr1.cc:847
    break;

  case 24:
#line 196 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = new StringExp(yystack_[0].value.as< std::string > ());}
#line 1251 "parsecalc.cc" // lalr1.cc:847
    break;

  case 25:
#line 197 "parsecalc.yy" // lalr1.cc:847
    {
  vars.affiche();
  yylhs.value.as< Exp* > ()=new Null();
}
#line 1260 "parsecalc.cc" // lalr1.cc:847
    break;

  case 26:
#line 201 "parsecalc.yy" // lalr1.cc:847
    {
  Calculator calc;
  std::cout<<vars.getVar(yystack_[0].value.as< std::string > ())->accept(calc)<<std::endl;;
  yylhs.value.as< Exp* > ()=new Null();
}
#line 1270 "parsecalc.cc" // lalr1.cc:847
    break;

  case 27:
#line 206 "parsecalc.yy" // lalr1.cc:847
    { if(isInBody){
          yylhs.value.as< Exp* > () = new LetExp();
          vars.newScope((LetExp*)yylhs.value.as< Exp* > ());
          isInBody=false;
          isInHead=true;
          isNewScope = true;
        } else{
          error(yystack_[0].location, "let can only be used in a body"); YYERROR;
        }
}
#line 1285 "parsecalc.cc" // lalr1.cc:847
    break;

  case 28:
#line 216 "parsecalc.yy" // lalr1.cc:847
    { 
  try{
          if(isInBody){
            vars.deleteScope();
            yylhs.value.as< Exp* > () = new Null();
          }else{
            error(yystack_[0].location, "end can only be used in a body"); YYERROR;
          }
        }catch( const std::string msg){
          error(yystack_[0].location, "no more scope to quit"); YYERROR;
        }
}
#line 1302 "parsecalc.cc" // lalr1.cc:847
    break;

  case 29:
#line 228 "parsecalc.yy" // lalr1.cc:847
    {
  if(isInHead){
    yylhs.value.as< Exp* > () = new Null();
    isInBody=true;
    isInHead=false;
  }else{
    error(yystack_[0].location, "in can only be used in a head"); YYERROR;
  }
}
#line 1316 "parsecalc.cc" // lalr1.cc:847
    break;

  case 30:
#line 237 "parsecalc.yy" // lalr1.cc:847
    {
  yylhs.value.as< Exp* > ()=new Null();
}
#line 1324 "parsecalc.cc" // lalr1.cc:847
    break;

  case 31:
#line 240 "parsecalc.yy" // lalr1.cc:847
    {
  yylhs.value.as< Exp* > ()=new Null();
}
#line 1332 "parsecalc.cc" // lalr1.cc:847
    break;

  case 32:
#line 243 "parsecalc.yy" // lalr1.cc:847
    {
  yylhs.value.as< Exp* > ()=new Null();
}
#line 1340 "parsecalc.cc" // lalr1.cc:847
    break;

  case 33:
#line 246 "parsecalc.yy" // lalr1.cc:847
    {
  yylhs.value.as< Exp* > ()=new Null();
}
#line 1348 "parsecalc.cc" // lalr1.cc:847
    break;

  case 34:
#line 252 "parsecalc.yy" // lalr1.cc:847
    {yylhs.value.as< Sequence* > () = new Sequence(yystack_[0].value.as< Exp* > ());}
#line 1354 "parsecalc.cc" // lalr1.cc:847
    break;

  case 35:
#line 253 "parsecalc.yy" // lalr1.cc:847
    {yystack_[2].value.as< Sequence* > ()->vector+yystack_[0].value.as< Exp* > (); yylhs.value.as< Sequence* > () = yystack_[2].value.as< Sequence* > ();}
#line 1360 "parsecalc.cc" // lalr1.cc:847
    break;


#line 1364 "parsecalc.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -38;

  const signed char parser::yytable_ninf_ = -1;

  const short int
  parser::yypact_[] =
  {
     -38,    53,   -38,    -3,   -38,    -7,   -38,    24,    87,   -38,
     119,   119,   119,   -38,   -38,    31,    38,   -38,   -38,   -38,
      37,    46,   -38,   121,   -38,   119,    28,    41,   152,    30,
      -8,    20,     6,    32,   -38,   -38,    39,   119,   119,   119,
     119,   -38,   152,   151,   -38,   -38,   119,   119,   119,   119,
     119,   183,    -5,    -5,   -38,   -38,    36,   -11,   152,    89,
      13,   152,   152,    43,     7,   -38,    45,   119,   119,   -38,
      47,   -38,   152,   152,   -38
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,    13,    23,    24,     0,     0,     4,
       0,     0,     0,    18,    19,     0,    25,    27,    29,    28,
       0,     0,     3,     0,     6,     0,     0,     0,    34,     0,
       0,     0,     0,     0,    26,    20,     0,     0,     0,     0,
       0,     5,    22,     0,    12,    11,     0,     0,     0,     0,
       0,     0,     8,     7,    10,     9,    19,     0,    35,    15,
       0,    17,    21,    19,     0,    33,     0,     0,     0,    32,
       0,    31,    14,    16,    30
  };

  const signed char
  parser::yypgoto_[] =
  {
     -38,   -38,   -38,    -1,   -37
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    22,    28,    29
  };

  const unsigned char
  parser::yytable_[] =
  {
      23,    37,    38,    46,    39,    40,    57,    39,    40,    30,
      31,    32,    24,    66,    64,    37,    38,    47,    39,    40,
      25,    46,    37,    38,    42,    39,    40,    49,    26,    37,
      38,    70,    39,    40,    68,    33,    52,    53,    54,    55,
      48,    45,    34,    35,    46,    58,    59,    60,    61,    62,
      36,    43,    44,     2,     3,     0,     4,     5,     6,    50,
       7,     8,    51,    65,     0,     0,    72,    73,     9,    10,
      69,    11,    71,     0,    74,    12,    13,    14,     0,    15,
       0,    16,    17,    18,    19,     0,    20,    21,    27,     0,
       4,     5,     6,     0,     7,     8,     0,     0,    37,    38,
       0,    39,    40,    10,     0,    11,    67,     0,     0,    12,
      13,    14,     0,    15,     0,    16,    17,    18,    19,     0,
      20,    21,     4,     5,     6,     0,     7,     8,     0,     0,
      37,    38,     0,    39,    40,    10,    41,    11,     0,     0,
       0,    12,    13,    14,     0,    15,     0,    16,    17,    18,
      19,     0,    20,    21,     4,     5,     6,     0,     7,     8,
       0,    37,    38,     0,    39,    40,     0,    10,     0,    11,
       0,     0,     0,    12,    13,    56,     0,    15,     0,    16,
      17,    18,    19,     0,    20,    21,     4,     5,     6,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,    10,
       0,    11,     0,     0,     0,    12,    13,    63,     0,    15,
       0,    16,    17,    18,    19,     0,    20,    21
  };

  const signed char
  parser::yycheck_[] =
  {
       1,     9,    10,    14,    12,    13,    43,    12,    13,    10,
      11,    12,    15,    24,    51,     9,    10,    25,    12,    13,
      27,    14,     9,    10,    25,    12,    13,    21,     4,     9,
      10,    24,    12,    13,    21,     4,    37,    38,    39,    40,
      20,    11,     4,     6,    14,    46,    47,    48,    49,    50,
       4,    23,    11,     0,     1,    -1,     3,     4,     5,    27,
       7,     8,    23,    27,    -1,    -1,    67,    68,    15,    16,
      27,    18,    27,    -1,    27,    22,    23,    24,    -1,    26,
      -1,    28,    29,    30,    31,    -1,    33,    34,     1,    -1,
       3,     4,     5,    -1,     7,     8,    -1,    -1,     9,    10,
      -1,    12,    13,    16,    -1,    18,    17,    -1,    -1,    22,
      23,    24,    -1,    26,    -1,    28,    29,    30,    31,    -1,
      33,    34,     3,     4,     5,    -1,     7,     8,    -1,    -1,
       9,    10,    -1,    12,    13,    16,    15,    18,    -1,    -1,
      -1,    22,    23,    24,    -1,    26,    -1,    28,    29,    30,
      31,    -1,    33,    34,     3,     4,     5,    -1,     7,     8,
      -1,     9,    10,    -1,    12,    13,    -1,    16,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    -1,    26,    -1,    28,
      29,    30,    31,    -1,    33,    34,     3,     4,     5,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    -1,    26,
      -1,    28,    29,    30,    31,    -1,    33,    34
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    36,     0,     1,     3,     4,     5,     7,     8,    15,
      16,    18,    22,    23,    24,    26,    28,    29,    30,    31,
      33,    34,    37,    38,    15,    27,     4,     1,    38,    39,
      38,    38,    38,     4,     4,     6,     4,     9,    10,    12,
      13,    15,    38,    23,    11,    11,    14,    25,    20,    21,
      27,    23,    38,    38,    38,    38,    24,    39,    38,    38,
      38,    38,    38,    24,    39,    27,    24,    17,    21,    27,
      24,    27,    38,    38,    27
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    35,    36,    36,    37,    37,    37,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    39,    39
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     2,     2,     3,     3,     3,
       3,     3,     3,     1,     6,     4,     6,     4,     1,     1,
       2,     4,     3,     1,     1,     1,     2,     1,     1,     1,
       6,     6,     5,     5,     1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "INT", "STRING", "STDSTRING",
  "FILENAME", "\"function\"", "\"(\"", "\"-\"", "\"+\"", "\")\"", "\"/\"",
  "\"*\"", "\";\"", "\"end of line\"", "\"if\"", "\"else\"", "\"for\"",
  "\"from\"", "\"to\"", "\"do\"", "\"while\"", "\"{\"", "\"}\"",
  "\"then\"", "\"var\"", "\"=\"", "\"affiche\"", "\"let\"", "\"in\"",
  "\"end\"", "\",\"", "\"import\"", "\"class\"", "$accept", "input",
  "line", "exp", "exps", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   108,   108,   109,   134,   135,   136,   142,   143,   144,
     145,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   168,   176,   189,   196,   197,   201,   206,   216,   228,
     237,   240,   243,   246,   252,   253
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
    };
    const unsigned int user_token_number_max_ = 289;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1853 "parsecalc.cc" // lalr1.cc:1155
#line 258 "parsecalc.yy" // lalr1.cc:1156

void yy::parser::error(const location_type& loc, const std::string& msg)
{
  std::cerr <<  loc;
  std::cerr << ": " << msg << "\n";
  *nerrs += 1;
}



int main()
{
  //yydebug = !!getenv("YYDEBUG");
  std::cout << Engine::vars2 << std::endl;
  std::cout << &vars << std::endl;
  unsigned nerrs =0;
  /*
  FILE* f = fopen("t.t","r");
  #define YY_STDINIT
  yyset_in(f);
  yyset_out(stdout);
  */
  yy::parser parser(&nerrs);
  nerrs += !!parser.parse();

  return !!nerrs;
}
