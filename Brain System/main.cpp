//Name : Ibrahim
//Roll # 13i-1821

#include <iostream>
#include <vector>
#include <cmath>
#include "neuron.h"
using namespace std;

int main()
{

  cout << "===== Test of 1st part  =====" << endl
       << endl;

  Neuron neuron1(0, 1, 0.5);
  Neuron neuron2(1, 0, 1.0);
  Neuron neuron3(1, 1, 2.0);

  neuron1 += &neuron2;
  neuron1 += &neuron3;
  neuron2 += &neuron3;

  cout << neuron1 << endl;

  neuron1.fire(10);

  cout << "Signals :" << endl;
  cout << neuron1.signal() << endl;
  cout << neuron2.signal() << endl;
  cout << neuron3.signal() << endl;

  cout << endl
       << "===== Test of 2nd part =====" << endl
       << endl;

  CumulativeNeuron neuron4(0, 0, 0.75);
  cout << neuron4 << endl;
  neuron4.fire(10);
  neuron4.fire(10);
  cout << "Signal :" << endl;
  cout << neuron4.signal() << endl;

  cout << "===== Test of Logical gate \"or\"   =====" << endl
       << endl;

  // building the architecture...
  // Here n1 and n2 will be our inputs, n0 will be always 1.

  Neuron n0(2, 0, -10);
  Neuron n1(1, 0, 20.0);
  Neuron n2(0, 0, 20.0);

  CumulativeNeuron n3(1, 3, 1); // will act as output

  n0 += &n3;
  n1 += &n3;
  n2 += &n3;

  n0.fire(1); // will always fire 1...n1.fire(0)
  n2.fire(1);

  cout << "If a=0 and b=1 then a|b == " << n3.signal() << endl;

  n1.fire(1);
  n2.fire(1);

  cout << "If a=1 and b=1 then a|b == " << n3.signal();

  n1.fire(0);
  n2.fire(0);

  cout << "If a=0 and b=0 then a|b == " << n3.signal();

  // Add the code for other logical gates..
  cout << "===== Test of Logical gates \"And, etc\"   =====" << endl
       << endl;

  // Copy paste the Test Code for xnor gate here.
  cout << "===== Test of Logical gate \"xnor\"   =====" << endl
       << endl;

  ComplexNeuron x0(2, 0);
  ComplexNeuron x1(1, 0); // x1 as input
  ComplexNeuron x2(0, 0); // x2 as input

  ComplexCumulativeNeuron x3(1, 3, 1);
  ComplexCumulativeNeuron x4(0, 3, 1);
  ComplexNeuron x6(3, 3, 1);

  ComplexCumulativeNeuron x5(6, 2, 1);

  // layer-1 neurons

  x0.attach(-30, &x3);
  x0.attach(10, &x4);

  x1.attach(20, &x3);
  x1.attach(-20, &x4);

  x2.attach(20, &x3);
  x2.attach(-20, &x4);

  // layer-2 neurons

  x6.attach(-10, &x5);

  x3.attach(20, &x5);
  x4.attach(20, &x5);

  x0.fire(1);
  x6.fire(1);

  //Lets start checking the system bycalling the fire
  // method of input neurons

  x1.fire(0);
  x2.fire(1);

  cout << "If a=0 and b=1 then  ̃(aˆb) == " << x5.signal();

  x1.fire(1);
  x2.fire(1);

  cout << "If a=1 and b=1 then  ̃(aˆb) == " << x5.signal();

  x1.fire(0);
  x2.fire(0);

  cout << "If a=0 and b=0 then  ̃(aˆb) == " << x5.signal();

  return 0;
}
