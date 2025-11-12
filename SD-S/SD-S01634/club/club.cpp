#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct people
{
	int a1;
	int a2;
	int a3;
	int delta;
	int b1;
	int b2;
	int b3;
};
people a[100010];
long long res=0;
bool cmp(people a1,people b1)
{
	return a1.delta>b1.delta;
}
void mxt()
{
	int n;
	cin>>n;
	res=0;
	int kind[4]={0,0,0,0};
	for (int i=1;i<=n;++i)
	{
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		a[i].b1=1;
		a[i].b2=2;
		a[i].b3=3;
		if(a[i].a1<a[i].a2) 
		{
			swap(a[i].a1,a[i].a2);
			swap(a[i].b1,a[i].b2);
		}
		if(a[i].a2<a[i].a3) 
		{
			swap(a[i].a2,a[i].a3);
			swap(a[i].b2,a[i].b3);
		}
		if(a[i].a1<a[i].a2) 
		{
			swap(a[i].a1,a[i].a2);
			swap(a[i].b1,a[i].b2);
		}
		a[i].delta=a[i].a1-a[i].a2;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;++i)
	{
		if(kind[a[i].b1]<(n/2))
		{
			++kind[a[i].b1];
			res+=a[i].a1;
		}
		else
		{
			++kind[a[i].b2];
			res+=a[i].a2;
		}
	}
	cout<<res<<'\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) mxt();
	return 0;
}
