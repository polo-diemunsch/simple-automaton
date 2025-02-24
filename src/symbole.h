#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, EXPR, FIN, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "EXPR", "FIN", "ERREUR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();

      int getValeur() { return valeur; };

   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr(int v): Symbole(EXPR), valeur(v) {}
      virtual ~Expr() {}
      virtual void Affiche();

      int getValeur() { return valeur; };

   protected:
      int valeur;
};

