#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[100];
int ans=0;
int t;
struct node
{
	pair<int,int> b1,b2,b3;
	int c;
}e[5000005];
bool cmp(node x,node y)
{
	if(x.c!=y.c) return x.c>y.c;
	else if(x.b1!=y.b1) return x.b1>y.b1;
	else if(x.b2!=y.b2) return x.b2>y.b2;
	else return x.b3>y.b3;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		int n;
		cin>>n;
		c[1]=n/2;
		c[2]=n/2;
		c[3]=n/2;
		for(int i=1;i<=n;i++)
		{
			pair<int,int> a1,a2,a3;
			cin>>a1.first>>a2.first>>a3.first;
			a1.second=1;
			a2.second=2;
			a3.second=3;
			if(a1.first<a2.first) swap(a1,a2);
			if(a2.first<a3.first) swap(a2,a3);
			if(a1.first<a2.first) swap(a1,a2);
			e[i].b1=a1;
			e[i].b2=a2;
			e[i].b3=a3;
			e[i].c=abs(a1.first-a2.first);
 		}
 		sort(e+1,e+n+1,cmp);
 		for(int i=1;i<=n;i++)
 		{
 			if(c[e[i].b1.second])
 			{
 				ans+=e[i].b1.first;
 				c[e[i].b1.second]--;
			}
			else if(c[e[i].b2.second])
			{
				ans+=e[i].b2.first;
				c[e[i].b2.second]--;
			}
			else
			{
				ans+=e[i].b3.first;
				c[e[i].b3.second]--;
			}
		}
 		cout<<ans<<"\n";
	}
	return 0;
}
