#include<bits/stdc++.h>
using namespace std;

int n,cnt=0;
int a[5050];
bool flag[5050]={};

void dfs(int step,int last,int maxn,int c)
{
	if(step>n)
	{
		int sum=0;
		if(c>=3)
		{
			for(int i=1;i<=n;i++) sum+=flag[i]*a[i];
			if(sum>maxn*2) cnt++;
			cnt%=998;
			cnt%=244;
			cnt%=353;
		}
		
		return;
	}
	for(int i=last+1;i<=n;i++)
	{
			flag[i]=true;
			dfs(step+1,i,max(maxn,a[i]),c+1);
			flag[i]=false;
			dfs(step+1,i,maxn,c);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<cnt<<endl;
	return 0;
}
