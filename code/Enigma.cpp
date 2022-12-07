#include "Enigma.h" 
Enigma::Enigma(std::string cle,std::string messagedecr) : Encrypt(messagedecr), _cle(cle)
{}
void Enigma::encode(){
	std::string Alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
	std::string _cle = "AZERTYUIOPQSDFGHJKLMWXCVBN" ;
	std::string encodage = _plain ;
	int tailleMessage= _plain.size();
	for (int i = 0 ; i < tailleMessage ; i++ ){
		for (int j = 0 ; j < 26 ; j++){
				if (_plain.at(i)==Alphabet.at(j)){
					encodage.at(i)=_cle.at(j) ;
				}

		}
	}
	_cipher=encodage ;

}
void Enigma::decode(){
	int tailleMessage = cipher().size();
	std::cout << " taille = " << tailleMessage << std::endl;
}
std::string Enigma::makecle(){
	std::string Alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	srand(time(NULL));
	random_shuffle(Alphabet.begin(), Alphabet.end());
	_cle=Alphabet ;
	return _cle;
}
