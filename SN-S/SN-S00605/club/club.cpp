//臧家乐  SN-S00605  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N][3];
struct node
{
	int a1,a2;
}x[N];
bool cmp(node q,node p)
{
	if(q.a1<=q.a2)
	{
		if(p.a1<=p.a2)
			return q.a1<p.a1;
		return q.a1<p.a2;
	}
	if(q.a2<=q.a1)
	{
		if(p.a1<=p.a2)
			return q.a2<p.a1;
		return q.a2<p.a2;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2],ans+=a[i][0];
		for(int i=1;i<=n;i++)
		{
			int m1=a[i][0]-a[i][1];
			int m2=a[i][0]-a[i][2];
			x[i].a1=m1,x[i].a2=m2;
		}
		sort(x+1,x+n+1,cmp);
		int num1=n/2;
		int num2=n/2;
		for(int i=1;i<=n;i++)
		{
			if(i>n/2 && ((x[i].a1>=0 && x[i].a2>=0 ) || (x[i].a1>=0 && num2<=0) || (x[i].a2>=0 && num1<=0)))
				break;
			if(x[i].a1<=x[i].a2 && num1>0)
			{
				num1--;
				ans-=x[i].a1;
				continue;
			}
			if(x[i].a2<=x[i].a1 && num2>0)
			{
				num2--;
				ans-=x[i].a2;
				continue;
			}
			if(num1<=0 && num2>0)
			{
				ans-=x[i].a2;
				num2--;
				continue;
			}
			if(num2<=0 && num1>0)
			{
				ans-=x[i].a1;
				num1--;
				continue;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
