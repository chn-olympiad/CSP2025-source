#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
//注意清空
int t,n,p,maxn,ans,ans1=0;
struct node{
	int m[4];
	int first,second;int d;
}; 
node a[N];
bool jk[N];
int k[5];
void dfs(int h,int w)
{
	if(h>n/2)
	{
		for(int i=1;i<=n;i++)
		{
			if(jk[i])ans1+=a[i].m[a[i].first];
			else ans1+=a[i].m[a[i].second]; 
		}
		ans=max(ans,ans1);
		ans1=0;
		return; 
	}
	for(int i=w+1;i<=k[p];i++)
	{
		jk[i]=1;
		dfs(h+1,i);
		jk[i]=0;
	}
}
bool cmp(node x,node y)
{
	if(x.first==p&&y.first==p)
	{
	return x.first<y.first; 
	}
	else if(x.first==p)return 1;
	else if(y.first==p)return 0;
	else return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(jk,0,sizeof(jk));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)cin>>a[i].m[j];
			a[i].d=i;
			int maxn=1;
			for(int j=2;j<=3;j++)
			{
				if(a[i].m[maxn]<a[i].m[j])
				{
					maxn=j;
				}
			}
			a[i].first=maxn;
			k[a[i].first]++;
			int q,mn=-1;
			for(int j=1;j<=3;j++)
			{
				if(j!=maxn)
				{
					if(a[i].m[j]>mn)
					{
						mn=a[i].m[j];
						q=j;
					}
				}
			}
			a[i].second=q;
		}
		bool v=0;
		for(int i=1;i<=3;i++)
		{
			if(k[i]>n/2)
			{
			v=1;
			p=i;
			stable_sort(a+1,a+1+n,cmp); 
			}
		}
		if(v==0)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=a[i].m[a[i].first];
			}
			cout<<ans<<endl;
		}
		else{
		dfs(1,0);
		cout<<ans<<endl;
		}
	}
	return 0;
}

//1-n/2
//1 2 3 
//