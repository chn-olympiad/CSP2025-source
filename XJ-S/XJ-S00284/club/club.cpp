#include<bits/stdc++.h>
using namespace std;
int mem[100005][5],n,flag[100],ans;
long long sum,maxx;
void  dfs(int t1,int z)
{
	if(t1==n)
	{
		if(sum>maxx)
		{
			maxx=sum;
		}
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		
		if(flag[i]<n/2)
		{
		 sum=sum+mem[z][i];
		 flag[i]++;
		 dfs(t1+1,z+1);
		sum=sum-mem[z][i];
		flag[i]--;
		}
	
	}
}
int main()
{
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(flag,0,sizeof(flag));
		memset(mem,0,sizeof(mem));
		int i,j,k;
		cin>>n;
		sum=0;
        maxx=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				cin>>mem[i][j];
			}
		}
		int w=0;
		dfs(w,1);
		cout<<maxx<<endl;
	}
	

	
	return 0;
} 
