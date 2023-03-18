#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int n, m;
const int maxn = 366, maxm = 101;
int rely[maxm];  //������ϵ
int t[maxm];  //����ʱ��
int fast[maxm];
int late[maxm];
vector<int> relied[maxm];  //��˭����

void calc_rely(int index)
{
	if (relied[index].empty())  //�����������ͽ���
	{
		return;
	}
	else
	{
		//��������
		for (int i = 0; i < relied[index].size(); i++)
		{
			fast[relied[index][i]] = fast[index] + t[index];
			calc_rely(relied[index][i]);  //�ݹ����
		}
	}
}

int calc_late(int index)
{
	//����ĳ��index������ʼʱ��
	int res;
	if (relied[index].empty())  //����������������Ϳ����ǵ����һ��ѵ�����
	{
		res = n - t[index] + 1;
		//late[index] = res;
		return res;
	}
	else
	{
		//����������
		int min = 400, tmp;
		for (int i = 0; i < relied[index].size(); i++)
		{
			tmp = calc_late(relied[index][i]);
			if (tmp < min)
			{
				min = tmp;
			}
		}
		//��Ҫ��tmp֮ǰ���ѵ��
		//late[index] = tmp - t[index];
		return (min - t[index]);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> rely[i];
		if (rely[i])
		{
			relied[rely[i]].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
	}

	//��ʼ�������翪ʼʱ�������ʼʱ��
	for (int i = 1; i <= m; i++)
	{
		if (rely[i] == 0) {
			//������˭�����翪ʼʱ����1
			fast[i] = 1;
			//��������������
			calc_rely(i);
		}
	}
	//���������翪ʼʱ��
	//70%���ݲ���Ҫ����ʼʱ��
	for (int i = 1; i <= m; i++) {
		cout << fast[i] << " ";
	}

	int flag = true;

	//��������������ʼʱ��
	for (int i = 1; i <= m; i++)
	{
		late[i] = calc_late(i);
		if (late[i] <= 0 || late[i] < fast[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << endl;
		for (int i = 1; i <= m; i++) {
			cout << late[i] << " ";
		}
	}
	return 0;
}