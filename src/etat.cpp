#include "etat.h"
#include "symbole.h"
#include <iostream>

void Etat::print() const {
    cout << "Etat " << name << endl;
}

bool E0::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionsimple(s, new E1);
            break;
        default:
            throw "Syntaxe invalide : " + Etiquettes[*s] + " à la position " + to_string(automate.getIndex());
    }
    return false;
}

bool E1::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case FIN:
            return true;
        default:
            throw "Syntaxe invalide : " + Etiquettes[*s] + " à la position " + to_string(automate.getIndex());
    }
    return false;
}

bool E2::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionsimple(s, new E6);
            break;
        default:
            throw "Syntaxe invalide : " + Etiquettes[*s] + " à la position " + to_string(automate.getIndex());
    }
    return false;
}

bool E3::transition(Automate & automate, Symbole * s) {
    Entier * s1;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            s1 = (Entier *) automate.popSymbol();
            automate.reduction(1, new Expr(s1->getValeur()));
            delete s1;
            break;
        default:
            throw "Syntaxe invalide : " + Etiquettes[*s] + " à la position " + to_string(automate.getIndex());
    }
    return false;
}

bool E4::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionsimple(s, new E7);
            break;
        default:
            throw "Syntaxe invalide : " + Etiquettes[*s] + " à la position " + to_string(automate.getIndex());
    }
    return false;
}

bool E5::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionsimple(s, new E8);
            break;
        default:
            throw "Syntaxe invalide : " + Etiquettes[*s] + " à la position " + to_string(automate.getIndex());
    }
    return false;
}

bool E6::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new E9);
            break;
        default:
            throw "Syntaxe invalide : " + Etiquettes[*s] + " à la position " + to_string(automate.getIndex());
    }
    return false;
}

bool E7::transition(Automate & automate, Symbole * s) {
    Expr * s1, * s2;
    switch (*s) {
        case PLUS:
        case CLOSEPAR:
        case FIN:
            s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new Expr(s1->getValeur() + s2->getValeur()));
            delete s1;
            delete s2;
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        default:
            throw "Syntaxe invalide : " + Etiquettes[*s] + " à la position " + to_string(automate.getIndex());
    }
    return false;
}

bool E8::transition(Automate & automate, Symbole * s) {
    Expr * s1, * s2;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new Expr(s1->getValeur() * s2->getValeur()));
            delete s1;
            delete s2;
            break;
        default:
            throw "Syntaxe invalide : " + Etiquettes[*s] + " à la position " + to_string(automate.getIndex());
    }
    return false;
}

bool E9::transition(Automate & automate, Symbole * s) {
    Expr * s1;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.popAndDestroySymbol();
            s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            automate.reduction(3, s1);
            break;
        default:
            throw "Syntaxe invalide : " + Etiquettes[*s] + " à la position " + to_string(automate.getIndex());
    }
    return false;
}
