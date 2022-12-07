#include "Encrypt.h" 
class Enigma : public Encrypt {
	public:
		Enigma(std::string messagedecr,std::string messagecr);
		void encode() override;
		void decode() override;
		std::string makecle();
	private:
		std::string _cle;
		std::string _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};
