//Name : Ibrahim
//Roll # 13i-1821
#ifndef Ibrahim
#define Ibrahim
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*__________________________________________________________________*/
class Point
{

  private:
	int x;
	int y;

  public:
	friend istream &operator>>(istream &in, Point &p);
	friend ostream &operator<<(ostream &out, const Point p);

	Point(int x, int y) : x(x), y(y) {}
	void setXY(int x, int y);
	void setX(int x);
	void setY(int y);
	void getXY(int &x, int &y);
	int getX();
	int getY();
	void display();
	float distance(const Point &p);
};
/*__________________________________________________________________*/
class Neuron
{

  protected:
	Point *position_;
	double signal_;
	double attenuation_;
	Neuron *n;

	int count;
	friend class CumulativeNeuron;

  public:
	Neuron() {}
	Neuron(int x, int y, double attenuation_ = 1)
	{
		position_ = new Point(x, y);
		this->attenuation_ = attenuation_;
		signal_ = 0;

		n = new Neuron[20];
		count = 0;
	}
	void operator+=(Neuron *p);
	void Position(int &x, int &y);
	double signal();
	void fire(double received_signal);
	void accumulate(double received_signal);
	void propagate();
	void display();
	double attenuation();
	int counter();

	friend ostream &operator<<(ostream &out, Neuron &n);
};
/*__________________________________________________________________*/
class CumulativeNeuron : public Neuron
{

	friend class Neuron;

  public:
	CumulativeNeuron(int x, int y, double attenuation_ = 1) : Neuron(x, y, attenuation_) {}
	void fire(double received_signal);
	void accumulate(double received_signal);
	void propagate();
	double signal();
};
/*__________________________________________________________________*/
class ComplexNeuron : public Neuron
{
  private:
	double attenuation[10];

  public:
	ComplexNeuron(int x, int y, double attenuation_ = 1) : Neuron(x, y, attenuation_) {}

	void attach(double attenuation, Neuron *p);
	void fire(double recieved_signal);
};
/*__________________________________________________________________*/
class ComplexCumulativeNeuron : public CumulativeNeuron
{
  private:
	double attenuation[10];

  public:
	ComplexCumulativeNeuron(int x, int y, double attenuation_ = 1) : CumulativeNeuron(x, y, attenuation_) {}
	void attach(double attenuation, Neuron *p);
};
#endif
