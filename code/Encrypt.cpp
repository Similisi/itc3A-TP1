#include "Encrypt.h" 
Encrypt::Encrypt(std::string messagedecr): _cipher(messagedecr){}

std::string Encrypt::plain(){
	return _plain;
}
std::string Encrypt::cipher() {
	return _cipher;
}