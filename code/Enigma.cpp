#include "Enigma.h" 
Enigma::Enigma(std::string messagedecr,std::string messagecr) : Encrypt(messagedecr,messagecr)
{}
void Enigma::encode(){
	std::string Alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
	std::string encodage = _plain ;
	std::string cle1 = _listecle.at(0);
	std::string cle2 = _listecle.at(1);
	int tailleMessage= _plain.size();
	for (int i = 0 ; i < tailleMessage ; i++ ){
		for (int j = 0 ; j < 26 ; j++){				
			if (_plain.at(i)==Alphabet.at(j)){
					encodage.at(i)=cle1.at(j) ;
				}
			}	
		}
		_plain=encodage ;
		for (int i =0 ; i < tailleMessage ; i++){
			for (int j = 0 ; j < 26 ; j++){
					if (_plain.at(i)==cle1.at(j)){
						encodage.at(i)=cle2.at(j) ;
					}
				}	

		}
	_cipher=encodage ;

}
void Enigma::decode(){
	std::string messageDecode = "";
	std::vector<std::string> listeRotor = _listecle;
	reverse(listeRotor.begin(),listeRotor.end());
	for(char lettredansmot : cipher()){
		char lettre;
		for(std::string rotor : listeRotor){ //faire pour 2 rotor ( 2 clés)
			//std::cout << "rotor = " << rotor << std::endl;
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
	std::string cle;
	srand(time(NULL));
	random_shuffle(Alphabet.begin(), Alphabet.end());
	cle=Alphabet ;
	_listecle.push_back(cle);
	sleep(1);
	return cle;
}
