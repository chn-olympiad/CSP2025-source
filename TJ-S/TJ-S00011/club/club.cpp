#include<bits/stdc++.h>
using namespace std;
int ans,n,v[4];
struct zh
{
	int d1,d2,d3;
};
zh an[100005];
void dfs(int x,int s,int a,int b,int c)
{
	if(x>n)
	{
		ans=max(ans,s);
		return;
	}
	if(a>0&&x<=n)
	{
		dfs(x+1,s+an[x].d1,a-1,b,c);
	}
	if(b>0&&x<=n)
	{
		dfs(x+1,s+an[x].d2,a,b-1,c);
	}
	if(c>0&&x<=n)
	{
		dfs(x+1,s+an[x].d3,a,b,c-1);
	}
}

int main(){
	freopen("club.in","r",stdin);
	int t;cin>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>n;
		v[1]=v[2]=v[3]=n/2;
		for(int j=1;j<=n;j++)
			cin>>an[j].d1>>an[j].d2>>an[j].d3;
		dfs(1,0,n/2,n/2,n/2);
		cout<<ans<<endl;
	}
	freopen("club.out","w",stdout);
	return 0;

}

