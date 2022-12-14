#include "Encrypt.h" 
class Enigma : public Encrypt {
	public:
		Enigma(std::string messagedecr,std::string messagecr);
		void encode() override;
		void decode() override;
		std::string makecle();
		void AjoutCle(std::string cle);
		std::vector<std::string> GetListeCle();
	private:
		std::vector<std::string> _listecle;
		std::string _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};
