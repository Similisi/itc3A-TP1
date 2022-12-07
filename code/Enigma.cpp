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
	std::string messageDecode = "";
	std::vector<std::string> listeRotor = {_cle};
	for(char lettredansmot : cipher()){
		char lettre;
		for(std::string rotor : listeRotor){
			int pos = rotor.find(toupper(lettredansmot));
			lettre = _alphabet.at(pos);
		}
		messageDecode += lettre;
	}
	_plain = messageDecode;
	std::cout << "resultat = " << messageDecode << std::endl;
}
std::string Enigma::makecle(){
	std::string Alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	srand(time(NULL));
	random_shuffle(Alphabet.begin(), Alphabet.end());
	_cle=Alphabet ;
	return _cle;
}
