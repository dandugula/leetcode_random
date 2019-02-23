class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      std::deque<int> index;
      std::vector<int> res(deck.size());

      std::sort(deck.begin(), deck.end());

      for(int i = 0; i < deck.size(); ++i)
        index.push_back(i);

      for(auto aCard: deck) {
        res[index.front()] = aCard;
        index.pop_front();

        if(!index.empty()) {
          index.push_back(index.front());
          index.pop_front();
        }
      }

      return res;
    }
};
