#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+3;
int n,t,ans=0;
int m[5][maxn],fm[5][maxn];
int tmp[4];
////DFS(记忆化搜索 
int dfs(int c,int s)
{	
	if(tmp[c]>=n/2)
		return 0;
	if(s==n) return m[c][s];
	int ans_=0;
	int i_;
	for(int i=1;i<=3;i++)
	{
		int firefly=dfs(i,s+1);
		if(firefly>=ans_) 
		{
			ans_=firefly;
			i_=i;
		}
	}
	for(int i=1;i<=n;i++)
		if(i!=i_) tmp[i]=0;
	tmp[i_]++;
//	cout<<"  \n"<<i_<<endl;
	return fm[c][s]=m[c][s]+ans_;
}

int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		memset(fm,sizeof(fm),0);
		memset(m,sizeof(m),0); 
		
		////输入部分 
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
				cin>>m[k][j];
		}
		ans=0; 
		for(int j=1;j<=4;j++)
			tmp[i]=0;
		for(int j=1;j<=3;j++)
			ans=max(ans,dfs(i,1));
		cout<<ans<<endl;
	}
	
	return 0;
}

 
