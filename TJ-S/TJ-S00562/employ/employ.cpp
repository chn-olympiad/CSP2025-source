#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long n,m,sum = 0,num = 0;
char s[N],c[N]; 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	long long p[n];
	for (long long i = 1;i <= n;i++)
	{
		cin >> s[i];
	}
	for (long long i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	for (long long i = 1;i <= n;i++)
	{
		if (s[i] == '0')
		{
			num++;
		}
		else
		{
			if (num < c[i])
			{
				sum++;
			}
			else
			{
				num++;
			}
		}
	}
	cout << sum;
	return 0;//ÎÒ°®return£¬return°®ÎÒ 
}
