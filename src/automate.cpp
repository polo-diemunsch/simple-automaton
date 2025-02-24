#include "automate.h"
#include "etat.h"
#include <iostream>

Automate::~Automate() {
    int n = symbolStack.size();
    for (int i = 0; i < n; i++) {
        popAndDestroySymbol();
    }

    n = stateStack.size();
    for (int i = 0; i < n; i++) {
        popAndDestroyState();
    }
}

int Automate::lecture() {
    Symbole * s = lexer->Consulter();
    stateStack.push_back(new E0);

    while (!(stateStack.back()->transition(*this, s))) {
        s = lexer->Consulter();
    }

    Expr * finalExpr = (Expr *) symbolStack.back();

    return finalExpr->getValeur();
}

void Automate::decalage(Symbole * s, Etat * e) {
    symbolStack.push_back(s);
    stateStack.push_back(e);
    lexer->Avancer();
}

void Automate::transitionsimple(Symbole * s, Etat * e) {
    symbolStack.push_back(s);
    stateStack.push_back(e);
}

void Automate::reduction(int n, Symbole * s) {
    for (int i = 0; i < n; i++) {
        popAndDestroyState();
    }
    stateStack.back()->transition(*this, s);
}

Symbole * Automate::popSymbol() {
    Symbole * symbole = symbolStack.back();
    symbolStack.pop_back();
    return symbole;
}

void Automate::popAndDestroySymbol() {
    delete (symbolStack.back());
    symbolStack.pop_back();
}

void Automate::popAndDestroyState() {
    delete (stateStack.back());
    stateStack.pop_back();
}
