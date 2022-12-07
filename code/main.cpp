#include "Enigma.h"
int main(){
    std::ofstream monFlux("resultat.txt");
    if(monFlux)  //On teste si tout est OK
    {
        //Tout est OK, on peut utiliser le fichier
        Enigma code("BONJOURCOMMENTALLEZVOUS","");
        code.makecle();
        code.encode();
        monFlux << "message crypté " << code.cipher() << std::endl;
        code.decode();
        monFlux << "message décrypté " << code.plain() << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }

    return 0;
}