#pragma once

#include <string>
#include <deque>
#include "lexer.h"
#include "symbole.h"
using namespace std;

class Etat;

class Automate {
    public:
        Automate(Lexer * l): lexer(l) { };
        ~Automate();

        int lecture();

        void decalage(Symbole * s, Etat * e);
        void transitionsimple(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);

        Symbole * popSymbol();
        void popAndDestroySymbol();
        void popAndDestroyState();

    protected:
        Lexer * lexer;
        deque<Symbole *> symbolStack;
        deque<Etat *> stateStack;
};
