#include "Encrypt.h" 
class Enigma : public Encrypt {
	public:
		Enigma(std::string _cle,std::string messagedecr);
		void encode() override;
		void decode() override;
		std::string makecle()
	private:
		std::string _cle;
};