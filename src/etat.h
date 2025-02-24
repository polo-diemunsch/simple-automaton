#pragma once

#include <string>
#include "automate.h"
#include "symbole.h"
using namespace std;

class Etat {
    public:
        Etat(string n): name(n) { };
        virtual ~Etat() { };
        void print() const;
        virtual bool transition(Automate & automate, Symbole * s) = 0;

    protected:
        string name;
};

class E0: public Etat {
    public:
        E0(): Etat("0") { };
        ~E0() { };
        bool transition(Automate & automate, Symbole * s);
};

class E1: public Etat {
    public:
        E1(): Etat("1") { };
        ~E1() { };
        bool transition(Automate & automate, Symbole * s);
};

class E2: public Etat {
    public:
        E2(): Etat("2") { };
        ~E2() { };
        bool transition(Automate & automate, Symbole * s);
};

class E3: public Etat {
    public:
        E3(): Etat("3") { };
        ~E3() { };
        bool transition(Automate & automate, Symbole * s);
};

class E4: public Etat {
    public:
        E4(): Etat("4") { };
        ~E4() { };
        bool transition(Automate & automate, Symbole * s);
};

class E5: public Etat {
    public:
        E5(): Etat("5") { };
        ~E5() { };
        bool transition(Automate & automate, Symbole * s);
};

class E6: public Etat {
    public:
        E6(): Etat("6") { };
        ~E6() { };
        bool transition(Automate & automate, Symbole * s);
};

class E7: public Etat {
    public:
        E7(): Etat("7") { };
        ~E7() { };
        bool transition(Automate & automate, Symbole * s);
};

class E8: public Etat {
    public:
        E8(): Etat("8") { };
        ~E8() { };
        bool transition(Automate & automate, Symbole * s);
};

class E9: public Etat {
    public:
        E9(): Etat("9") { };
        ~E9() { };
        bool transition(Automate & automate, Symbole * s);
};
