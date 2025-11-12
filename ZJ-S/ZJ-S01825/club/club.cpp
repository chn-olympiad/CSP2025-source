#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[100005];
bool cmp(node x,node y)
{
	return x.v>y.v;
}
long long t,ans,a1,a2,a3,b[5],n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		b[1]=b[2]=b[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1>>a2>>a3;
			if(a1>=a2&&a1>=a3)
			{
				a[i].u=a1;
				a[i].v=a1-max(a2,a3);
				a[i].w=1;
			}
			else if(a2>=a1&&a2>=a3)
			{
				a[i].u=a2;
				a[i].v=a2-max(a1,a3);
				a[i].w=2;
			}
			else if(a3>=a1&&a3>=a2)
			{
				a[i].u=a3;
				a[i].v=a3-max(a1,a2);
				a[i].w=3;
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].u;
			b[a[i].w]++;
			if(b[a[i].w]>n/2)
				ans-=a[i].v;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
