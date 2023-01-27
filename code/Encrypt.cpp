#include "Encrypt.h" 
Encrypt::Encrypt(std::string messagedecr,std::string messagecrypte): _plain(messagedecr), _cipher(messagecrypte){}
//retourne message non chiffré
std::string Encrypt::plain(){
	return _plain;
}
//retourne message chiffré
std::string Encrypt::cipher() {
	return _cipher;
}

//ajoute message non chiffré
void Encrypt::setplain(std::string text){
	_plain = text;
}
//ajoute message chiffré
void Encrypt::setcipher(std::string text){
	_cipher = text;
}
