#include "Enigma.h"
int main(){
    
    std::ifstream monFlux2("resultat.txt");
    std::string text,ligne;
    //Tout est OK, on peut utiliser le fichier
    while(getline(monFlux2,ligne)){
        std::cout << "te = " << ligne << std::endl;
        text+=ligne;
    }

    std::ofstream monFlux("resultat.txt");
    if(monFlux)  //On teste si tout est OK
    {
        int choix =0;
        std::cout << "Que voulez vous faire ? (1 : encoder / 2 : decoder )" << std::endl;
        std::cin >> choix;
        Enigma code("","");
        switch (choix)
        {
            case 1:
                code.setplain(text);
                for(int index = 0 ; index < 2 ; index++){
                    code.makecle();
                }
                code.encode();
                monFlux << code.cipher() << std::endl;
                for(std::string cle:code.GetListeCle()){
                    monFlux << "cle = " << cle << std::endl;
                }
                break;
            case 2:
                code.setcipher(text);
                for(int index = 0 ; index < 2 ; index++){
                    std::string cl;
                    std::cout << "clé = ";
                    std::cin >> cl;
                    code.AjoutCle(cl);
                }
                code.decode();
                monFlux << code.plain() << std::endl;
                break;
            
            default:
                break;
        }

    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }

    return 0;
}