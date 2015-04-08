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

  #include <stdio.h>
  #include <stdlib.h>
  #include <map>
  #include <vector>
  #include "Scope.hh"
  
  Variables vars;

#line 44 "parsecalc.cc" // lalr1.cc:392


// First part of user declarations.

#line 49 "parsecalc.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parsecalc.hh"

// User implementation prologue.

#line 63 "parsecalc.cc" // lalr1.cc:407


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
#line 149 "parsecalc.cc" // lalr1.cc:474

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
      case 28: // line
      case 29: // exp
        value.copy< Exp* > (other.value);
        break;

      case 3: // INT
        value.copy< int > (other.value);
        break;

      case 4: // STRING
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
      case 28: // line
      case 29: // exp
        value.copy< Exp* > (v);
        break;

      case 3: // INT
        value.copy< int > (v);
        break;

      case 4: // STRING
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
      case 28: // line
      case 29: // exp
        value.template destroy< Exp* > ();
        break;

      case 3: // INT
        value.template destroy< int > ();
        break;

      case 4: // STRING
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
      case 28: // line
      case 29: // exp
        value.move< Exp* > (s.value);
        break;

      case 3: // INT
        value.move< int > (s.value);
        break;

      case 4: // STRING
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
      case 28: // line
      case 29: // exp
        value.move< Exp* > (that.value);
        break;

      case 3: // INT
        value.move< int > (that.value);
        break;

      case 4: // STRING
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
      case 28: // line
      case 29: // exp
        value.copy< Exp* > (that.value);
        break;

      case 3: // INT
        value.copy< int > (that.value);
        break;

      case 4: // STRING
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
            case 28: // line

#line 43 "parsecalc.yy" // lalr1.cc:617
        { yyo << yysym.value.template as< Exp* > (); }
#line 667 "parsecalc.cc" // lalr1.cc:617
        break;

      case 29: // exp

#line 43 "parsecalc.yy" // lalr1.cc:617
        { yyo << yysym.value.template as< Exp* > (); }
#line 674 "parsecalc.cc" // lalr1.cc:617
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
      case 28: // line
      case 29: // exp
        yylhs.value.build< Exp* > ();
        break;

      case 3: // INT
        yylhs.value.build< int > ();
        break;

      case 4: // STRING
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
#line 81 "parsecalc.yy" // lalr1.cc:847
    { 
                std::stringstream ss;
                std::string s;
                ss<<*yystack_[0].value.as< Exp* > ();
                s = ss.str();
                if(s!="null"){
                  std::cout<<*yystack_[0].value.as< Exp* > ()<<std::endl;
                  vars.newExp(yystack_[0].value.as< Exp* > ());
                  vars.addExp(yystack_[0].value.as< Exp* > ());
                }
              }
#line 923 "parsecalc.cc" // lalr1.cc:847
    break;

  case 4:
#line 95 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = yylhs.value.as< Exp* > ()=new Null(); }
#line 929 "parsecalc.cc" // lalr1.cc:847
    break;

  case 5:
#line 96 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = yystack_[1].value.as< Exp* > (); }
#line 935 "parsecalc.cc" // lalr1.cc:847
    break;

  case 6:
#line 97 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = yylhs.value.as< Exp* > ()=new Null(); yyerrok; }
#line 941 "parsecalc.cc" // lalr1.cc:847
    break;

  case 7:
#line 101 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createBin('+',yystack_[2].value.as< Exp* > (), yystack_[0].value.as< Exp* > ()); }
#line 947 "parsecalc.cc" // lalr1.cc:847
    break;

  case 8:
#line 102 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createBin('-',yystack_[2].value.as< Exp* > (), yystack_[0].value.as< Exp* > ()); }
#line 953 "parsecalc.cc" // lalr1.cc:847
    break;

  case 9:
#line 103 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createBin('*',yystack_[2].value.as< Exp* > (), yystack_[0].value.as< Exp* > ()); }
#line 959 "parsecalc.cc" // lalr1.cc:847
    break;

  case 10:
#line 104 "parsecalc.yy" // lalr1.cc:847
    {  Engine calc;
                  double i=(*yystack_[0].value.as< Exp* > ())();
                  if(i){
                    yylhs.value.as< Exp* > () = createBin('/',yystack_[2].value.as< Exp* > (), yystack_[0].value.as< Exp* > ()); 
                  }else{
                    error(yystack_[0].location, "division by 0");
                    YYERROR;
                  }
                }
#line 973 "parsecalc.cc" // lalr1.cc:847
    break;

  case 11:
#line 113 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = yystack_[1].value.as< Exp* > (); }
#line 979 "parsecalc.cc" // lalr1.cc:847
    break;

  case 12:
#line 114 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createNum(777); }
#line 985 "parsecalc.cc" // lalr1.cc:847
    break;

  case 13:
#line 115 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createNum(yystack_[0].value.as< int > ()); }
#line 991 "parsecalc.cc" // lalr1.cc:847
    break;

  case 14:
#line 116 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createIf(yystack_[4].value.as< Exp* > (),yystack_[2].value.as< Exp* > (),yystack_[0].value.as< Exp* > ());}
#line 997 "parsecalc.cc" // lalr1.cc:847
    break;

  case 15:
#line 117 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createIf(yystack_[2].value.as< Exp* > (),yystack_[0].value.as< Exp* > ());}
#line 1003 "parsecalc.cc" // lalr1.cc:847
    break;

  case 16:
#line 118 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createFor(yystack_[4].value.as< Exp* > (),yystack_[2].value.as< Exp* > (),yystack_[2].value.as< Exp* > (),yystack_[0].value.as< Exp* > ());vars.newScope();vars.newVar(((Var*) yystack_[4].value.as< Exp* > ())->name_, ((Var*) yystack_[4].value.as< Exp* > ())->val_);}
#line 1009 "parsecalc.cc" // lalr1.cc:847
    break;

  case 17:
#line 119 "parsecalc.yy" // lalr1.cc:847
    { yylhs.value.as< Exp* > () = createWhile(yystack_[2].value.as< Exp* > (),yystack_[0].value.as< Exp* > ());}
#line 1015 "parsecalc.cc" // lalr1.cc:847
    break;

  case 18:
#line 120 "parsecalc.yy" // lalr1.cc:847
    { vars.newScope(); yylhs.value.as< Exp* > ()=new Null(); }
#line 1021 "parsecalc.cc" // lalr1.cc:847
    break;

  case 19:
#line 121 "parsecalc.yy" // lalr1.cc:847
    { try{
    vars.deleteScope();
    yylhs.value.as< Exp* > ()=new Null();
  }catch(const std::string & Msg){
    error(yystack_[0].location, "No more scope to quit"); YYERROR;
  }
}
#line 1033 "parsecalc.cc" // lalr1.cc:847
    break;

  case 20:
#line 128 "parsecalc.yy" // lalr1.cc:847
    {
  try{
    vars.newVar(yystack_[0].value.as< std::string > (),0); 
    yylhs.value.as< Exp* > ()=createVar(yystack_[0].value.as< std::string > (),0);
  }catch(const std::string& msg){
    error(yystack_[0].location,msg);YYERROR;
  }
}
#line 1046 "parsecalc.cc" // lalr1.cc:847
    break;

  case 21:
#line 137 "parsecalc.yy" // lalr1.cc:847
    {
 try{
    vars.newVar(yystack_[2].value.as< std::string > (),(*yystack_[0].value.as< Exp* > ())()); 
    yylhs.value.as< Exp* > ()=createVar(yystack_[2].value.as< std::string > (),(*yystack_[0].value.as< Exp* > ())());
  }catch(const std::string& msg){
    error(yystack_[2].location,msg);YYERROR;
  }
}
#line 1059 "parsecalc.cc" // lalr1.cc:847
    break;

  case 22:
#line 145 "parsecalc.yy" // lalr1.cc:847
    {
  bool res = vars.hasVar(yystack_[2].value.as< std::string > ());
  try{
    if(res){
      vars.setVar(yystack_[2].value.as< std::string > (),(*yystack_[0].value.as< Exp* > ())());
      yylhs.value.as< Exp* > () = new Assignment(yystack_[2].value.as< std::string > (),(*yystack_[0].value.as< Exp* > ())());
    }else{
      error(yystack_[2].location, "is not an existed variable"); YYERROR;
    }
  }catch(const std::string & Msg){
    error(yystack_[2].location, "truc de merde"); YYERROR;
  }
}
#line 1077 "parsecalc.cc" // lalr1.cc:847
    break;

  case 23:
#line 158 "parsecalc.yy" // lalr1.cc:847
    { try{
              yylhs.value.as< Exp* > () = createNum(vars.getVar(yystack_[0].value.as< std::string > ()));
            } catch(const std::string & Msg){
              error(yystack_[0].location, "not a statement"); YYERROR;
            }
}
#line 1088 "parsecalc.cc" // lalr1.cc:847
    break;

  case 24:
#line 164 "parsecalc.yy" // lalr1.cc:847
    {
  vars.affiche();
  yylhs.value.as< Exp* > ()=new Null();
}
#line 1097 "parsecalc.cc" // lalr1.cc:847
    break;


#line 1101 "parsecalc.cc" // lalr1.cc:847
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


  const signed char parser::yypact_ninf_ = -16;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
     -16,    31,   -16,   -11,   -16,   -15,    44,   -16,    57,    57,
      57,   -16,   -16,    11,   -16,   -16,    96,   -16,    57,    10,
     103,     1,    82,     7,     0,    57,    57,    57,    57,   -16,
     108,   -16,   -16,    57,    57,    57,    57,    -4,    -4,   -16,
     -16,    87,    77,   108,   108,    57,    57,   108,   108
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,    13,    23,     0,     4,     0,     0,
       0,    18,    19,     0,    24,     3,     0,     6,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     5,
      22,    12,    11,     0,     0,     0,     0,     8,     7,    10,
       9,    15,     0,    17,    21,     0,     0,    14,    16
  };

  const signed char
  parser::yypgoto_[] =
  {
     -16,   -16,   -16,    -6
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    15,    16
  };

  const unsigned char
  parser::yytable_[] =
  {
      20,    17,    21,    22,    23,    27,    28,    25,    26,    18,
      27,    28,    30,    25,    26,    24,    27,    28,    31,    37,
      38,    39,    40,    33,    36,    35,     0,    41,    42,    43,
      44,     2,     3,     0,     4,     5,     6,     0,     0,    47,
      48,     0,     0,     7,     8,    19,     9,     4,     5,     6,
      10,    11,    12,     0,    13,     0,    14,     8,     0,     9,
       4,     5,     6,    10,    11,    12,     0,    13,     0,    14,
       8,     0,     9,     0,     0,     0,    10,    11,    12,     0,
      13,     0,    14,    25,    26,     0,    27,    28,    25,    26,
       0,    27,    28,    25,    26,    46,    27,    28,     0,    34,
       0,    45,    25,    26,     0,    27,    28,     0,    29,    25,
      26,    32,    27,    28,    25,    26,     0,    27,    28
  };

  const signed char
  parser::yycheck_[] =
  {
       6,    12,     8,     9,    10,     9,    10,     6,     7,    24,
       9,    10,    18,     6,     7,     4,     9,    10,     8,    25,
      26,    27,    28,    22,    24,    18,    -1,    33,    34,    35,
      36,     0,     1,    -1,     3,     4,     5,    -1,    -1,    45,
      46,    -1,    -1,    12,    13,     1,    15,     3,     4,     5,
      19,    20,    21,    -1,    23,    -1,    25,    13,    -1,    15,
       3,     4,     5,    19,    20,    21,    -1,    23,    -1,    25,
      13,    -1,    15,    -1,    -1,    -1,    19,    20,    21,    -1,
      23,    -1,    25,     6,     7,    -1,     9,    10,     6,     7,
      -1,     9,    10,     6,     7,    18,     9,    10,    -1,    17,
      -1,    14,     6,     7,    -1,     9,    10,    -1,    12,     6,
       7,     8,     9,    10,     6,     7,    -1,     9,    10
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    27,     0,     1,     3,     4,     5,    12,    13,    15,
      19,    20,    21,    23,    25,    28,    29,    12,    24,     1,
      29,    29,    29,    29,     4,     6,     7,     9,    10,    12,
      29,     8,     8,    22,    17,    18,    24,    29,    29,    29,
      29,    29,    29,    29,    29,    14,    18,    29,    29
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    26,    27,    27,    28,    28,    28,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     2,     2,     3,     3,     3,
       3,     3,     3,     1,     6,     4,     6,     4,     1,     1,
       2,     4,     3,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "INT", "STRING", "\"(\"",
  "\"-\"", "\"+\"", "\")\"", "\"/\"", "\"*\"", "\";\"", "\"end of line\"",
  "\"if\"", "\"else\"", "\"for\"", "\"from\"", "\"to\"", "\"do\"",
  "\"while\"", "\"{\"", "\"}\"", "\"then\"", "\"var\"", "\"=\"",
  "\"affiche\"", "$accept", "input", "line", "exp", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    80,    80,    81,    95,    96,    97,   101,   102,   103,
     104,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     128,   137,   145,   158,   164
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
      25
    };
    const unsigned int user_token_number_max_ = 280;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1556 "parsecalc.cc" // lalr1.cc:1155
#line 171 "parsecalc.yy" // lalr1.cc:1156

void yy::parser::error(const location_type& loc, const std::string& msg)
{
  std::cerr <<  loc;
  std::cerr << ": " << msg << "\n";
  *nerrs += 1;
}

int main()
{
  //yydebug = !!getenv("YYDEBUG");
  unsigned nerrs = 0;
  yy::parser parser(&nerrs);
  nerrs += !!parser.parse();

  return !!nerrs;
}
