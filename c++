#include <iostream>
#include <cmath>
#include <iomanip>
/*minifoo = nый член ряда Тейлора*/
using namespace std;
int main()
{
	double x;
	int k, p;
	cout << "Enter x" << endl;
	cin >> x;
	if (x > 1 || x < -1) {
		cout << "ERROR" << endl;
		return 0;
	}
	
		cout << "Enter the calculation accuracy - k" << endl;
		cin >> k;
		double function = 1;
	int minifoo = 1;
		for (p = 1; fabs(minifoo) > (pow(10, -k)); p++) {
			minifoo *= (double)x * p * (2 * p- 1) / (2 * p * p);
			if (p % 2 == 0) {
				function += (double)minifoo / (1 - 2 * p);
			}
			else {
				function -= (double)minifoo / (1 - 2 * p);
			}
		}
		cout << "Result:\n";
		cout << fixed << setprecision(k) << function << endl
			<< "The result calculated by the standard function:" << endl <<
			pow(1 + x, 0.5) << endl << "Calculation error:" << endl << "\u0394 = " <<
			fabs(function - pow(1 + x, 0.5)) << endl;
		return 0;

}
