#include <iostream>
#include <vector>
template<class PenPolicy>
class Writer {
  public:
   Writer(const PenPolicy& pen = PenPolicy()) : mPen(pen) { }
   void startWrite() {
     mPen.write();
   }
  private:
   PenPolicy mPen;
};
class InkPen {
  public:
    void write(){
      std::cout << "Writing with Ink Pen" << std::endl;
    }
};
class BallPointPen {
  public:
    void write() {
      std::cout << "Writing with Ball Point Pen" << std::endl;
    }
};

int main () {
  Writer<InkPen> inkWriter;
  BallPointPen bPen = BallPointPen();
  Writer<BallPointPen> ballPointWriter(bPen);

  inkWriter.startWrite();
  ballPointWriter.startWrite();

  return 0;
}
