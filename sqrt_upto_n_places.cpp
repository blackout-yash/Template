#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// n = 9

	int num = 50;
	double ans = sqrt(num);
	printf("%0.9lf\n", ans);


	ans = 0;
	int num1 = 34, num2 = 56;
	ans += sqrt(num1 * num1);
	ans += sqrt(num2 * num2);
	printf("%0.9lf\n", ans);

	return 0;
}