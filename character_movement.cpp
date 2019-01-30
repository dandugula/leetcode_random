#include <iostream>
#include <list>
class JumpingJack {
  private:
    std::list<int> board;
    std::list<int>::iterator cur_elem;
    //int cur_elem;
  public:
    JumpingJack(int n, int pos) {
      for(int i = 0; i < n; ++i) {
        board.push_back(i);
        if(pos == i)
          cur_elem = std::prev(board.end());
      }
    }
    void jumpLeft() {
      auto cur = cur_elem; 
      int n = 2;
      do {
        --cur_elem;
      } while(board.begin() != cur_elem && --n);
      if(board.begin() == cur_elem && 0 != n) {
        cur_elem = cur;
        return;
      }
      board.erase(cur);
    }

    void jumpRight() {
      auto cur = cur_elem; 
      int n = 2;
      do {
        ++cur_elem;
      } while(board.end() != cur_elem && --n);
      if(board.end() == cur_elem && 0 != n) {
        cur_elem = cur;
        return;
      }
      board.erase(cur);
    }

    int position() {
      return *cur_elem;
    }
    void disp() {
      std::cout << "**********************" << std::endl;
      for(auto i : board) {
        std::cout << i << " ";
      }
      std::cout << std::endl;
      std::cout << "**********************" << std::endl;
    }
};
int main (){
  JumpingJack j(6, 3);
  std::cout << j.position() << std::endl;
  j.disp();

  j.jumpLeft();
  std::cout << j.position() << std::endl;
  j.disp();

  j.jumpRight();
  std::cout << j.position() << std::endl;
  j.disp();
  
  j.jumpRight();
  std::cout << j.position() << std::endl;
  j.disp();
}
