#ifndef AST_H_INCLUDED
#define AST_H_INCLUDED

#include "RecursiveDescentP.h"

struct AST //Abstract Syntax Tree
{
    token *root = nullptr;

    void print(std::ostream& o){
        printRaw(o, root);
    }

    void printRaw(std::ostream& o, token* p, const std::string& prefix = "", bool isTail = true);
    void parse(std::stringstream& ss);
    void parse(std::stringstream& ss, std::ostream& o);

    void atomizeNegation(token* x);
    void atomizeNegation(){atomizeNegation(root);}

    void CNF(token* x);
    void CNF(){CNF(root);}

    ~AST(){postDestruct(root);}

    void postDestruct(token *x);
};

#endif // AST_H_INCLUDED
