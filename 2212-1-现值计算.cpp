#include<iostream>
#include<math.h>
using namespace std;

double n;
double i;

double calc(double num, double k)
{
	//����δ����k�����ֵnum�����㵱�µĵȼ���ֵ
	double res;
	res = num * pow((1 + i), -k);
	return res;
}

int main()
{
	cin >> n >> i;
	double ans = 0;
	double num;
	for (int j = 0; j <= n ; j++)
	{
		cin >> num;
		num = calc(num, j);
		ans += num;
	}
	cout << ans;
	return 0;
}