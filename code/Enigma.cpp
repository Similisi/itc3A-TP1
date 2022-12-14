#include "Enigma.h" 
Enigma::Enigma(std::string messagedecr,std::string messagecr) : Encrypt(messagedecr,messagecr)
{}
void Enigma::encode(){
	std::string messageDecode = "";
	std::vector<std::string> listeRotor = _listecle;
	std::string Alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
	//reverse(listeRotor.begin(),listeRotor.end());
	//std::cout << "rotor 1 = " << listeRotor.at(0) << std::endl;
	//std::cout << "rotor 2 = " << listeRotor.at(1) << std::endl;
	for(char lettredansmot : plain()){
		char lettre = lettredansmot;
		for(std::string rotor : listeRotor){ //faire pour 2 rotor ( 2 clés)
			//std::cout << "rotor = " << rotor << std::endl;
			int pos = Alphabet.find(toupper(lettre));
			//std::cout << lettre << " devient ";
			lettre = rotor.at(pos);
			//std::cout << lettre << std::endl;
		}
		//std::cout << "message = " << messageDecode << std::endl;
		messageDecode += lettre;
	}
	_cipher = messageDecode;
	//std::cout << "resultat = " << messageDecode << std::endl;
	/*std::string Alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
	std::string encodage = _plain ;
	std::string buffer = "" ;
	int tailleMessage= _plain.size();
	for(std::string clef: _listecle){
		for (int i = 0 ; i < tailleMessage ; i++ ){
			for (int j = 0 ; j < 26 ; j++){				
				if (encodage.at(i)==Alphabet.at(j)){
						encodage.at(i)=clef.at(j) ;
					}
				}	
			}
			buffer=encodage;
		}
	_cipher=buffer ;*/
}
void Enigma::decode(){
	std::string messageDecode = "";
	std::vector<std::string> listeRotor = _listecle;
	reverse(listeRotor.begin(),listeRotor.end());
	//std::cout << "rotor 1 = " << listeRotor.at(0) << std::endl;

	//std::cout << "rotor 2 = " << listeRotor.at(1) << std::endl;
	for(char lettredansmot : cipher()){
		char lettre = lettredansmot;
		for(std::string rotor : listeRotor){ //faire pour 2 rotor ( 2 clés)
			//std::cout << "rotor = " << rotor << std::endl;
			int pos = rotor.find(toupper(lettre));
			//std::cout << lettre << " devient ";
			lettre = _alphabet.at(pos);
			//std::cout << lettre << std::endl;
		}
		//std::cout << "message = " << messageDecode << std::endl;
		messageDecode += lettre;
	}
	_plain = messageDecode;
	//std::cout << "resultat = " << messageDecode << std::endl;
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

void Enigma::AjoutCle(std::string cle){
	_listecle.push_back(cle);
}

std::vector<std::string> Enigma::GetListeCle(){
	return _listecle;
}
