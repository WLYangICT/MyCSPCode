#include<iostream>
#include<math.h>
#include<vector>
#include<cmath>
using namespace std;
double Q[8][8], M[8][8], Mn[8][8];  //8*8����������
int r[8][8];
int n, T;  //ɨ�����ݸ���������
double pi = acos(-1);

double get_u(double u)
{
	if (u)
	{
		return 1;
	}
	else
	{
		return pow(0.5, 0.5);
	}
}

double get_value(double i, double j, double u, double v)
{
	double ans;
	double au = get_u(u), av = get_u(v);
	double Muv = M[(int)u][(int)v];
	double cos1 = cos((pi / 8) * (i + 0.5) * u);
	double cos2 = cos((pi / 8) * (j + 0.5) * v);
	ans = au * av * Muv * cos1 * cos2;
	return ans;
}

int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> Q[i][j];
		}
	}
	cin >> n >> T;

	if (n == 0)  //û����������
	{

	}
	else if (n >= 1)
	{
		cin >> M[0][0];
		int cin_num = 1;
		int dir_flag = 1;  //��ʶ�����߻��������� -1�����£�x+=1,y-=1;1�����ϣ�x-=1,y+=1
		int b_i = 0, b_j = 1;  //��ʼ���±�
		if (n == 1)
		{
			goto label;
		}
		for (int i = 1; i <= 7; i++)  //�տ�ʼ��7��
		{
			for (int j = 1; j <= i + 1; j++)
			{
				if (cin_num < n)
				{
					cin >> M[b_i][b_j];
					cin_num++;
				}
				else
				{
					goto label;
				}
				b_i += dir_flag * 1;
				b_j += dir_flag * (-1);
			}
			if (b_j == -1)  //���������
			{
				b_j = 0;
				dir_flag *= -1;
			}
			if (b_i == -1)  //�����ϱ���
			{
				b_i = 0;
				dir_flag *= -1;
			}
		}
		//��������������
		if (cin_num >= n)
		{
			goto label;
		}
		b_i = 7, b_j = 1;
		dir_flag = -1;  //����
		for (int i = 1; i <= 6; i++)  //�տ�ʼ��7��
		{
			for (int j = 1; j <= 8 - i; j++)
			{
				if (cin_num < n)
				{
					cin >> M[b_i][b_j];
					cin_num++;
				}
				else
				{
					goto label;
				}
				b_i += dir_flag * 1;
				b_j += dir_flag * (-1);
			}
			//����ȥ
			b_i -= dir_flag * 1;
			b_j -= dir_flag * (-1);
			if (b_j == 7)  //���������
			{
				b_i += 1;
				dir_flag *= -1;
			}
			if (b_i == 7)  //�����ϱ���
			{
				b_j += 1;
				dir_flag *= -1;
			}
		}
		if (cin_num < n)
		{
			cin >> M[7][7];
		}
		else
		{
			goto label;
		}

	label:  //�������
		int nothing = 0;
	}
	

	if (T == 0)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << M[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}

	//�������������
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			M[i][j] = M[i][j] * Q[i][j];
		}
	}

	if (T == 1)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << M[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}

	//��������Ҫ����õ����յĽ����
	double ans;
	for (double i = 0; i < 8; i++)
	{
		for (double j = 0; j < 8; j++)
		{
			ans = 0;
			//cout << "----" << endl;;
			for (double u = 0; u < 8; u++)
			{
				for (double v = 0; v < 8; v++)
				{
					ans += get_value(i, j, u, v);
					//cout << get_value(i, j, u, v) << endl;
				}
			}
			//cout << "----" << endl;
			ans /= 4.0;
			Mn[(int)i][(int)j] = ans;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Mn[i][j] += 128;
			r[i][j] = round(Mn[i][j]);
			if (r[i][j] > 255)
			{
				r[i][j] = 255;
			}
			if (r[i][j] < 0)
			{
				r[i][j] = 0;
			}
		}
	}

	if (T == 2)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << r[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}
	return 0;
}