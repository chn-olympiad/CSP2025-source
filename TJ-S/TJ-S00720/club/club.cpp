#include <bits/stdc++.h>

using namespace std;

int a1[100001],a2[100001],a3[100001];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,m=0;
	cin >>t;
	for (int k=0;k<t;k++)
	{
		cin >>n;
		for (int i=1;i<=n;i++)
		{
			cin >>a1[i]>>a2[i]>>a3[i];
		}
		sort(a1+1,a1+1+n);
		for (int i=n;i>n/2;i--)
		{
			m+=a1[i];
		}
		cout <<m<<endl;
	}return 0;
}
		
