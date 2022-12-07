#include "Encrypt.h" 
class Enigma : public Encrypt {
	public:
		Enigma(std::string messagedecr,std::string messagecr);
		void encode() override;
		void decode() override;
		std::string makecle();
	private:
		std::vector<std::string> _listecle;
		std::string _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};
