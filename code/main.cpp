#include "Enigma.h"
int main(){
    Enigma code("BONJOUR","");
    code.makecle();
    code.encode();
    std::cout << "message crypté " << code.cipher() << std::endl;
    code.decode();
    std::cout << "message décrypté " << code.plain() << std::endl;
    return 0;
}