#include<iostream>
#include<string>
#include<vector>
int minDistance(std::string word1, std::string word2)
{
  std::vector<std::vector<int> > temp(word2.size() + 1);
  temp[0].push_back(0);
  for(int i = 1; i < word1.size() + 1; ++i)
    temp[0].push_back(i);
  for(int i = 1; i < word2.size() + 1; ++i)
    temp[i].push_back(i);
  for(int i = 1; i <= word2.size(); ++i)
    for(int j = 1; j <= word1.size(); ++j)
      if(word1[j-1] == word2[i-1])
        temp[i].push_back(temp[i-1][j-1]);
      else
        temp[i].push_back(std::min(temp[i-1][j-1], std::min(temp[i-1][j], temp[i][j-1])) + 1);
  return temp[word2.size()][word1.size()];
}
int main() {
  return 0;
}
