#include "Encrypt.h" 
Encrypt::Encrypt(std::string messagedecr,std::string messagecrypte): _cipher(messagecrypte),_plain(messagedecr){}

std::string Encrypt::plain(){
	return _plain;
}
std::string Encrypt::cipher() {
	return _cipher;
}


void Encrypt::setplain(std::string text){
	_plain = text;
}
void Encrypt::setcipher(std::string text){
	_cipher = text;
}
