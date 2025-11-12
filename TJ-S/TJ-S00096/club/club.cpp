#include<bits/stdc++.h>
using namespace std;

struct member
{
	int a,b,c;
};

int t,n,maxn=-1;
member l[100010];
int flag[100010];

void dfs(int step,int cnta,int cntb,int cntc)
{
	if(cnta>n/2||cntb>n/2||cntc>n/2) return ;
	if(step>n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==1) 
			{
				sum+=l[i].a;
				cnta++;
			}
			else if(flag[i]==2) 
			{
				sum+=l[i].b;
				cntb++;
			}
			else
			{
				sum+=l[i].c;
				cntc++;
			}
		}
		maxn=max(maxn,sum);
		return;
	}
	flag[step]=1;
	dfs(step+1,cnta+1,cntb,cntc);
	flag[step]=2;
	dfs(step+1,cnta,cntb+1,cntc);
	flag[step]=3;
	dfs(step+1,cnta,cntb,cntc+1);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		maxn=-1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i].a>>l[i].b>>l[i].c;
		}
		dfs(1,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
}
