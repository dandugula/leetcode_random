#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

typedef std::pair<std::string, int> freq_pair;
//AppDynamics Interview
void printMyFreq(std::vector<std::string>& myVec)
{
  std::map<std::string, int> word_freq;
  std::vector<freq_pair> sorted;
   for(auto aString : myVec) {
     if(word_freq.find(aString) != word_freq.end())
       word_freq[aString]++;
     else
       word_freq.insert(std::make_pair(aString, 1));
   }
  std::copy(word_freq.begin(), word_freq.end(), 
            std::back_inserter<std::vector<freq_pair>>(sorted));
  std::sort(sorted.begin(), sorted.end(), [](const freq_pair& l, const freq_pair& r) { 
                                              if(l.second != r.second) 
                                                return l.second > r.second;
                                              return l.first < r.first;
           });
  std::for_each(sorted.begin(), sorted.end(), [](freq_pair& aPair) { 
                std::cout << aPair.first << "=>" << aPair.second << std::endl;});
  return;
}
int main() {
  std::vector<std::string> words = {"I", "I", "am", "am", "az", "az", "I", "here"};
  printMyFreq(words);
}
