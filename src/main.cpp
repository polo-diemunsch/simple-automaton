#include <iostream>
#include "automate.h"
#include "lexer.h"

int main(void) {
   string chaine("(1+34)*123");

   Lexer lexer(chaine);
   Automate automate = Automate(&lexer);

   cout << "Analyse de l'expression : " << chaine << endl;

   try {
      int result = automate.lecture();
      cout << "Résultat : " << result << endl;
   }
   catch (const string & error) {
      cout << error << endl;
   }

   return 0;
}

