#include <iostream>
#include <string>

template <typename OutputPolicy, typename LanguagePolicy>
class HelloWorld : private OutputPolicy, private LanguagePolicy {
  using OutputPolicy::print;
  using LanguagePolicy::message;
  
public:
  void run() {
    print(message());
  }
};

class OutputToCout {
  protected:
    void print(const std::string& msg) {
      std::cout << msg << std::endl;
    }
};

class TeluguLanguage {
  protected:
    std::string message() {
      return std::move("Namaskaram");
    }
};

class EnglishLanguage {
  protected:
    std::string message() {
      return std::move("Hello World");
    }
};

int main () {
  HelloWorld <OutputToCout, TeluguLanguage> HelloTel;
  HelloWorld <OutputToCout, EnglishLanguage> HelloEng;

  HelloTel.run();
  HelloEng.run();

  return 0;
}
