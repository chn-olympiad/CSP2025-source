#include <bits/stdc++.h>
using namespace std;
	int n;
int main()
{
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	cin >> n;
	int bi1, bi2;
	bi1 = n % 2;
	if (bi1 == 0)
	{
		cout << "输入正确" << endl;
	}
	else if(bi1 != 0)
	{
		cout << "输入不正确";
		return 0;
	}
	int ai1, ai2, ai3;
	cin >> ai1 >> ai2 >> ai3;
	int aip;
	if (ai1 >= n / 2)
	{
		aip = ai1;
	}
	else if(ai2 >= n / 2)
	{
		aip = ai2;
	}
	else if(ai3 >= n / 2)
	{
		aip = ai3;
	}
	if(aip >= n / 2)
	{
		cout << "部门人数过多";
		return 0; 
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			cout << "最好分配如下：" << endl;
			cout << "为一个部门：" << (ai1 + ai2 + ai3) / 3 << "人";
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
