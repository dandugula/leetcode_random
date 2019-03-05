class Solution {
private:
	inline bool isVowel(char ch) {
		if (ch == 'a' || ch == 'e' || ch == 'i' ||
			ch == 'o' || ch == 'u')
			return true;
		return false;
	}
public:
	string toGoatLatin(string S) {
		std::istringstream stream(S);
		std::string aWord;
		std::string ret;
		int index = 1;

		while (stream >> aWord) {
			std::string suff(index, 'a');

			if (isVowel(std::tolower(aWord[0])))
				aWord += "ma" + suff;
			else {

				suff = aWord[0] + std::string("ma") + suff;
				aWord = aWord.substr(1);
				aWord += suff;
			}

			ret += " " + aWord;
			++index;
		}

		return ret.substr(1);
	}
};
