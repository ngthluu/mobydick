# Mobydick programming language
Mobydick programming language is a simple, compiled and functional programming language. The compiler (v1.0) is written in C. 
## Lexical elements
- ID
- Numeric
    - Integer
    - Real
- String
- Operator
    - Logical: And `&&`, Or `||`, Not `!!`, Is `==`, Greater `>`, Less `<`, Greater or equal `>=`, Less of equal `<=`
    - Arithmetic: Add `+`, Sub `-`, Mul `*`, Div `/`, Mod `%`, Power `^`, Factorial `!`
    - Conditional: If `?`
- Bracket: `( ) { }`
- Seperator: Comma `,` Semicolon `;`
- Special token
    - Assign `=`
    - Infer `=>`

## Types
- There are 4 types in this language: Integer, Real, Boolean, String, Function.
- The operators can be used in these types:
    - Integer: Add, Sub, Mul, Div, Mod, Power, Factorial, Greater, Greater or equal, Less, Less or equal.
    - Real: Add, Sub, Mul, Div, Greater, Greater or equal, Less, Less or equal.
    - Boolean: And, Or, Not, Is.
    - String: Add.

## Syntax
- Everything in mobydick is an **expression**.
- Every seperate expression must be seperated by semicolon `;`.
- Assign expression: `ID = expression`. The value of this expression is `expression`.
- Conditional expression: `expression1 ? expression2` (if `expression2` true then the value is `expression1`, `null` otherwise).
- Function expression: `(ID_1, ID_2,..., ID_n) => {<expression_list>}`. The value of this expression is a function.
- Return expression: `=> expression`.
- Function call expression: `ID(arg_1, arg_2,..., arg_n)`. The value of this expression is the result of this function.
- Binary expression: `expression1 OP expression2`.
- Unary expression: `OP expression1`.

## Parser rules
```
program     -> expression+
expression  -> expression ';'
            -> '(' (ID (, ID)*)* ')' '=>' '{' expression* '}'
            -> ID '=' expression
            -> '(' expression ')'
            -> ID '(' (expression (, expression)*)* ')'
            
            -> '=>' expression
            -> '-' expression
            -> expression '!'
            -> '!!' expression
            
            -> expression '^' expression
            -> expression ('*' '/') expression
            -> expression ('+' '-') expression
            -> expression ('<' '>' '<=' '>=') expression
            -> expression ('&&' '||' '==') expression
            
            -> ID
            -> IntLit
            -> RealLit
            -> StringLit
```