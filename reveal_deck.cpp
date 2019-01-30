class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      std::vector<int> simulator(deck.size());
      std::vector<int> ret(deck.size());

      std::sort(deck.begin(), deck.end());
      std::for_each(simulator.begin(), simulator.end(), [](int &i) { static int id = 0; i = id++; });

      std::vector<int>::iterator sIt = simulator.begin();
      std::vector<int>::iterator dIt = deck.begin();

     while(!simulator.empty() && dIt != deck.end()) {
        ret[*sIt] = *dIt;
        ++dIt;

        sIt = simulator.erase(sIt);
        if(sIt == simulator.end()) break;

        simulator.push_back(*sIt);
        sIt = simulator.erase(sIt); 
      }

      simulator.clear();
      return ret;
    }
};
