//Name : Ibrahim
//Roll # 13i-1821

#include "neuron.h"

ostream &operator<<(ostream &out, Neuron &n)
{

	n.display();

	return out;
}
/*__________________________________________________________________*/
istream &operator>>(istream &in, Point &p)
{

	cout << "Enter X :";

	in >> p.x;

	cout << "Enter Y :";

	in >> p.y;

	return in;
}
/*__________________________________________________________________*/
ostream &operator<<(ostream &out, const Point p)
{

	out << "X :" << p.x << endl;

	out << "Y :" << p.y << endl;

	return out;
}
/*__________________________________________________________________*/
void Point::display()
{

	cout << "X :" << x << endl
		 << "Y :" << y << endl;
}
/*__________________________________________________________________*/
float Point::distance(const Point &p)
{

	return sqrt(((x - p.x) * (x - p.x)) + ((y - p.y) * (y - p.y)));
}
/*__________________________________________________________________*/
void Point::setXY(int x, int y)
{

	this->x = x;

	this->y = y;
}
/*__________________________________________________________________*/
void Point::setX(int x)
{

	this->x = x;
}
/*__________________________________________________________________*/
void Point::setY(int y)
{

	this->y = y;
}
/*__________________________________________________________________*/
void Point::getXY(int &x, int &y)
{

	x = this->x;

	y = this->y;
}
/*__________________________________________________________________*/
int Point::getX()
{

	return x;
}
/*__________________________________________________________________*/
int Point::getY()
{

	return y;
}
/*__________________________________________________________________*/
int Neuron::counter()
{

	return count;
}
/*__________________________________________________________________*/
void Neuron::Position(int &x, int &y)
{

	position_->getXY(x, y);
}
/*__________________________________________________________________*/
double Neuron::signal()
{

	return signal_;
}
/*__________________________________________________________________*/
void Neuron::operator+=(Neuron *p)
{

	n[count] = *p;
	count++;
}
/*__________________________________________________________________*/
double Neuron::attenuation()
{

	return attenuation_;
}
/*__________________________________________________________________*/
void Neuron::fire(double received_signal)
{
	//cout<<"fired\n";
	accumulate(received_signal);

	//cout << "its Neuron\n";
	propagate();
}
/*__________________________________________________________________*/
void Neuron::accumulate(double received_signal)
{

	signal_ = attenuation_ * received_signal;
}
/*__________________________________________________________________*/
void Neuron::propagate()
{

	for (int i = 0; i < count; i++)
	{

		n[i].fire(signal_);
	}
}
/*__________________________________________________________________*/
double CumulativeNeuron::signal()
{

	return signal_;
}
/*__________________________________________________________________*/
void Neuron::display()
{

	int x, y;

	position_->getXY(x, y);

	cout << "The Neuron at position (" << x << "," << y

		 << " )"

		 << " with an attenuation factor " << attenuation() <<

		"  is connected to following  " << count << "  Neurons :\n";

	if (count != 0)
	{

		for (int i = 0; i < count; i++)
		{

			cout << "- Neuron at position ("

				 << n[i].position_->getX() << "," <<

				n[i].position_->getY() << ")\n";
		}
	}
	else
	{
		cout << "Not connected to any Neuron\n";
	}
}
/*__________________________________________________________________*/
void CumulativeNeuron::fire(double recieved_signal)
{

	this->accumulate(recieved_signal);

	this->propagate();
}
/*__________________________________________________________________*/
void CumulativeNeuron::accumulate(double received_signal)
{

	//cout << "its cum\n";

	signal_ = received_signal;

	for (int i = 0; i < count; i++)
	{

		signal_ = signal_ + n[i].signal();
	}
}
/*__________________________________________________________________*/
void CumulativeNeuron::propagate()
{

	cout << "its cum\n";

	signal_ = (1 / (1 + exp(-signal_))) * attenuation_;

	for (int i = 0; i < count; i++)
	{

		n[i].fire(signal_);
	}
}

/*__________________________________________________________________*/
void ComplexNeuron::attach(double attenuation_, Neuron *p)
{

	attenuation[count] = attenuation_;

	n[count] = *p;

	count++;
}
/*__________________________________________________________________*/
void ComplexNeuron::fire(double recieved_signal)
{
	double signal;

	for (int i = 0; i < count; i++)
	{

		signal = attenuation[i] * recieved_signal;

		n[i].fire(signal);
	}
}
/*__________________________________________________________________*/
void ComplexCumulativeNeuron::attach(double attenuation_, Neuron *p)
{

	attenuation[count] = attenuation_;

	n[count] = *p;

	count++;
}
/*__________________________________________________________________*/

/*__________________________________________________________________*/
