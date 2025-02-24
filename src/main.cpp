#include <iostream>
#include "automate.h"
#include "lexer.h"

int main(void) {
   cout << "Entrez une expression :" << endl;

   string chaine;
   getline(cin, chaine);

   if (chaine.empty()) {
      chaine = "(1+34)*123";
   }

   Lexer lexer(chaine);
   Automate automate = Automate(&lexer);

   cout << "Analyse de l'expression '" << chaine << "'" << endl;

   try {
      int result = automate.lecture();
      cout << "Résultat : " << result << endl;
   }
   catch (const string & error) {
      cout << error << endl;
   }

   return 0;
}

