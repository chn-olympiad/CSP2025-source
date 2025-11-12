#include<bits/stdc++.h>
using namespace std;
struct IP
{
	int d, b, c;
}a[100010];
int cmp(IP x,IP y)
{
	return x.d>=y.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>> t;
	while(t--)
	{
		int n;
		cin>> n;
		int m1=n/2, m2=n/2, m3=n/2;
		for(int i=0;i<n;i++)
			cin>> a[i].d>> a[i].b>> a[i].c;
		sort(a,a+n,cmp);
		int ans=0;
		for(int i=0;i<n/2;i++)
		{
			ans+=a[i].d;
		}
		cout<< ans;
	}
	return 0;
}
