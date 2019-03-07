class Complex{
  private:
    int mA, mB;
  public:
    Complex(int a, int b);
    Complex(const std::string& c_num);
    Complex operator*(Complex b); 
    int getReal();
    int getImg();
    std::string to_string();
};

Complex::Complex(int a, int b) : mA(a), mB(b) {
}

Complex::Complex(const std::string& c_num) {
  std::istringstream stream(c_num);
  std::string token;

  std::getline(stream, token, '+');
  mA = std::stoi(token);

  std::getline(stream, token, '+');
  mB = std::stoi(token.substr(0, token.size()-1));
}

Complex Complex::operator*(Complex b) {

  return Complex(this->getReal() * b.getReal() - this->getImg() * b.getImg(),
                 this->getImg() * b.getReal() + this->getReal() * b.getImg());
}

int Complex::getReal() {
  return mA;
}

int Complex::getImg() {
  return mB;
}

std::string Complex::to_string() {
  return std::to_string(mA) + "+" + std::to_string(mB) + "i";
}

class Solution {
public:
  string complexNumberMultiply(string a, string b) {
    return (Complex(a) * Complex(b)).to_string();
  }
};
