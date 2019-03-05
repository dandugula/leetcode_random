class Solution {
public:
	vector<string> uncommonFromSentences(string A, string B) {
		std::map<std::string, int> freqMap;
		std::vector<std::string> res;
		std::istringstream st(A + " " + B);
		std::string aWord;

		while (st >> aWord) {
			if (freqMap.find(aWord) == freqMap.end())
				freqMap.insert(std::make_pair(aWord, 1));
			else
				freqMap[aWord]++;
		}

		std::for_each(freqMap.begin(), freqMap.end(),
			[&res](auto aPair) { if (1 == aPair.second) res.push_back(aPair.first); });
		return res;
	}
};