#include <iomanip>
#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//建立 
	int n = 0,z = 0;
	string s;
	long long a[100005];
	cin >> s;
	//把数字字符提取出来 
	for(int i = 0;i <= s.size();i++)
	{
		if(	)//咋提取字符串元素啊... 
		{
			a[n] = ; 
			n += 1;
		}
	}
	//获得拼数最大值 
	for(int i = 1;i <= n;i++) 
	{
		for(int j = 0;j <= n - 1 - i;j++)
		{
			if(a[j] <= a[j + 1])
			{
				z = a[j];
				a[j] = a[j + 1];
				a[j + 1] = z; 
			}
		}
	}
	cout << a;
	
	return 0;
}
