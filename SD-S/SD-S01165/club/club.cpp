#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int p[5];
int cnt[100005];
struct node{
	int num;
	int tot;
};
node m[5];
int ans;
bool px(int x,int y)
{
	return x>y;
}
bool py(node x,node y)
{
	return x.num>y.num;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=5;i++)
		{
			p[i]=0;
		}
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>m[j].num;
				m[j].tot=j;
			}
			sort(m+1,m+1+n,py);
			p[m[1].tot]++;
			ans+=m[1].num;
			cnt[i]=m[2].num-m[1].num;
		}
		for(int t=1;t<=3;t++)
		{
			if(p[t]>(n/2))
			{
				sort(cnt+1,cnt+n+1,px);
				for(int j=1;j<=p[t]-n/2;j++)
				{
					ans+=cnt[j];
				}
			}
		}
		cout<<ans<<endl;
	}
	/*
	3
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	2
	10 9 8
	4 0 0
	18 4 13
	*/
	return 0;
} 
