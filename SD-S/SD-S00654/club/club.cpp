#include<bits/stdc++.h>
using namespace std;

const int MAX=300;

int ans;
int T;
int n;
int a[MAX][4];


void dfs(int now,int v,int x,int y,int z)
{
	if(x>n/2||y>n/2||z>n/2) return;
	if(now==n+1){
		ans=max(v,ans);
		return;
	}
    dfs(now+1,v+a[now][1],x+1,y,z);
    dfs(now+1,v+a[now][2],x,y+1,z);
    dfs(now+1,v+a[now][3],x,y,z+1);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
	    ans=0;
	    for(int i=1;i<=n;i++)
	    {
		    cin>>a[i][1]>>a[i][2]>>a[i][3];
	    }
	    dfs(1,0,0,0,0);
	    cout<<ans<<"\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}


