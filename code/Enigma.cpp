#include "Enigma.h" 
Enigma::Enigma(std::string cle,std::string messagedecr) : Encrypt(messagedecr), _cle(cle)
{}
void Enigma::encode(){}
void Enigma::decode(){
	int tailleMessage = cipher().size();
	std::cout << " taille = " << tailleMessage << std::endl;
}
