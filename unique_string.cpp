#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

class UniqueString {
  private:
    std::string getUserName(char* uname) {
      std::string ret = "";
      for(int i = 0; i < strlen(uname); ++i) {
        if(uname[i] == '.') continue;
        if(uname[i] == '+') break;
        ret += uname[i];
      }
      return ret;
    }
  public:
    static std::string unique(const std::vector<std::string>& names) {
      std::map<std::string, std::set<std::string>> users;
      int count = 0;
      for(auto aEmail : names) {
        char *uname = strtok(aEmail.c_str(), '@');
        char *domain = strtok(NULL, '@');
        std::string user = getUserName(uname);
        auto email = counts.find(std::string(domain));
        if(email != counts.end()) {
          if((email->second.insert(user)).second == true)
            ++count;
        } else {
          counts.insert(std::make_pair(std::string(domain), std::set<std::string>()));
          counts[std::string(domain)].second.insert(user);
          ++count;
        }
      }
    }
};

int main () {
  //std::vector<std::string> names = {"Madhu", "Chaitanya", "Madhu", "Arijit"};
  std::vector<std::string> names = {"Madhu", "Madhu", "Chaitanya", "Chaitanya"};
  std::cout << UniqueString::unique(names) << std::endl;
}
