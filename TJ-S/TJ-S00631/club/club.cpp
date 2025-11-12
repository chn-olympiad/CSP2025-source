#include<bits/stdc++.h>
using namespace std;
struct join
{
	int a,b,c;
	bool f;
} j[100001];
int t,n;
bool cmp(join x,join y)
{
	return x.a>x.b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>j[i].a>>j[i].b>>j[i].c;
		}
		sort(j+1,j+1+n,cmp);
		for(int i=1;i<=n/2;i++)
		{
			sum+=j[i].a;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
