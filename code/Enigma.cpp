#include "Enigma.h" 
Enigma::Enigma(std::string messagedecr,std::string messagecr) : Encrypt(messagedecr,messagecr)
{}
//methode d'encodage
void Enigma::encode(){
	std::string messageDecode = "";
	std::vector<std::string> listeRotor = _listecle;
	std::string Alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
	for(char lettredansmot : plain()){
		char lettre = lettredansmot;
		for(std::string rotor : listeRotor){ //faire pour 2 rotor ( 2 clés)
			int pos = Alphabet.find(toupper(lettre));
			lettre = rotor.at(pos);
		}
		messageDecode += lettre;
	}
	_cipher = messageDecode;
}
//methode de décodage
void Enigma::decode(){
	std::string messageDecode = "";
	std::vector<std::string> listeRotor = _listecle;
	reverse(listeRotor.begin(),listeRotor.end());
	for(char lettredansmot : cipher()){
		char lettre = lettredansmot;
		for(std::string rotor : listeRotor){ //faire pour 2 rotor ( 2 clés)
			int pos = rotor.find(toupper(lettre));
			lettre = _alphabet.at(pos);
		}
		messageDecode += lettre;
	}
	_plain = messageDecode;
}
//méthode pour créer une clé
std::string Enigma::makecle(){
	std::string Alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string cle;
	srand(time(NULL));
	random_shuffle(Alphabet.begin(), Alphabet.end());
	cle=Alphabet ;
	_listecle.push_back(cle);
	sleep(1);
	return cle;
}
//ajout de clé dans la liste des clé
void Enigma::AjoutCle(std::string cle){
	_listecle.push_back(cle);
}
//retourne la liste des clé
std::vector<std::string> Enigma::GetListeCle(){
	return _listecle;
}
