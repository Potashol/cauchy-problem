#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>

using namespace std;

double f(double x, double y)
{
	return x + y / x;
}

void euler_method(int N, double a, double b, double yi)
{
	ofstream fout("output.txt");
	double h = (b - a) / N;
	double xi = a;
	fout << "X" << " " << "Y" << endl;
	for (int i = 0; i < N - 1; ++i)
	{
		double xi_1 = xi + h;
		double h_i = xi_1 - xi;
		double y_i1 = yi + h_i * f(xi, yi);
		fout << xi << " " << y_i1 << endl;
		xi = xi_1;
		yi = y_i1;
	}
	fout.close();
}

double f1(double x, double y, double z)
{
	cout << ((sin(x)) / x) + z << " " << x << " " << -y << endl;
	return  z + sin(x) / x;
}

double f2(double x, double y, double z)
{
	return -(z * z) + (3.5 * x) / (1 + x * x);
}

void euler_method(int N, double a, double b, double yi, double zi)
{
	double h = (b - a) / N;
	double xi = a;
	ofstream fout("output2.txt");
	fout << "Y" << " " << "Z" << " " << "X" << endl;
	for (int i = 0; i <= N; ++i)
	{
		double xi_1 = xi + h;
		double h_i = xi_1 - xi;
		double y_i1 = yi + h_i * f1(xi * 10, yi * 10, zi * 10);
		double z_i1 = zi + h_i * f2(xi, yi, zi);
		fout << y_i1 << " " << z_i1 << " " << xi << endl;
		yi = y_i1;
		zi = z_i1;
		xi = xi_1;
	}
	fout.close();
}
int main()
{
	euler_method(10, 1, 1.5, 0);
	euler_method(20, 0.00001, 1, 0, -0.4112);
}