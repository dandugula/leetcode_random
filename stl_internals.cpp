#include <iostream>
#include <vector>

class VectorElement {
  int* data;
public:
  VectorElement() : data(new int(70)) {
    std::cout << "Default Constructor" << std::endl;
  }
  VectorElement(const VectorElement& rhs) : data(new int (*rhs.data)) {
    std::cout << "Copy Constructor" << std::endl;
    //data = rhs.data;
  }
  
  VectorElement(VectorElement&& rhs) : data(new int (*rhs.data)) {
    std::cout << "Move Constructor" << std::endl;
    rhs.data = nullptr;
  }
  VectorElement& operator=(VectroElement&& rhs) {
    std::cout << "Move Assignment operator" << std::endl;
    data = rhs.data;
    rhs.data = nullptr;
    return *this;
  } 
};
void vec_capacity() {
  std::vector<int> vec(1);
  std::cout << "Initial capcity: " << vec.capacity() << std::endl;
  vec.push_back(100);
  std::cout << "Initial capcity: " << vec.capacity() << std::endl;
  vec.push_back(100);
  std::cout << "Initial capcity: " << vec.capacity() << std::endl;
  vec.push_back(100);
  std::cout << "Initial capcity: " << vec.capacity() << std::endl;
  vec.push_back(100);
  std::cout << "Initial capcity: " << vec.capacity() << std::endl;

  vec.pop_back();
  std::cout << "After a pop: " << vec.capacity() << std::endl;
  vec.pop_back();
  std::cout << "After a pop: " << vec.capacity() << std::endl;
  vec.pop_back();
  std::cout << "After a pop: " << vec.capacity() << std::endl;
  vec.pop_back();
  std::cout << "After a pop: " << vec.capacity() << std::endl;

  return;
}
void vec_element() {
  std::vector<VectorElement> VectorElements;
  std::cout << "Initial capcity: " << VectorElements.capacity() << std::endl;
  VectorElements.push_back(VectorElement());
  std::cout << "Initial capcity: " << VectorElements.capacity() << std::endl;
  VectorElements.push_back(VectorElement());
  std::cout << "Initial capcity: " << VectorElements.capacity() << std::endl;
  VectorElements.push_back(VectorElement());
  std::cout << "Initial capcity: " << VectorElements.capacity() << std::endl;
  VectorElements.push_back(VectorElement());
  std::cout << "Initial capcity: " << VectorElements.capacity() << std::endl;

  std::vector<VectorElement>::iterator it = VectorElements.begin();
  while (it != VectorElements.end()) {
    it = VectorElements.erase(it);
  }
  return;
}
int main() {
  std::vector<int> vec(10, 100);
  vec[5] = 60;
  for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
    if(*it == 60) vec.erase(it);
  }
  for(auto aNum : vec) {
    std::cout << aNum << std::endl;
  }
  vec_capacity();
  vec_element();
  return 0;
}
