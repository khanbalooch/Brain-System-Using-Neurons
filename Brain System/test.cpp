#include <iostream>
using namespace std;

class A
{

  public:
    A *ptr;
    A() { ptr = new A[5]; }
    void out() { cout << "Its A\n"; }
    void call(A *p)
    {
        ptr[0] = *p;
        ptr[0].out();
    }
};
class B : public A
{
  public:
    void out() { cout << "its B\n"; }
};
int main()
{
    A a;
    B b;
    a.call(&b);
    return 0;
}
