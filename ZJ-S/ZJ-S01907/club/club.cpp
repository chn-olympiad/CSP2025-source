#include<bits/stdc++.h>
using namespace std;
int t,n,use[100005],f[100005][5],nm[4],ans;
void dfs(int i)
{
	if(i>n){
		nm[1]=0;nm[2]=0;nm[3]=0;
		int ansi=0;
		for(int i=1;i<=n;i++){
			nm[use[i]]++;
			ansi+=f[i][use[i]];
		}
		for(int i=1;i<=3;i++) 
		if(nm[i]>(n/2)) return;
		ans=max(ans,ansi);
		return ;}
	for(int j=1;j<=3;j++){
		use[i]=j;
		dfs(i+1);
	}
	}
	
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ti=1;ti<=t;ti++)
	{	bool fa=true,fb=true;
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{	cin>>f[i][1]>>f[i][2]>>f[i][3];
			if(f[i][3]!=0) {
				fb=false;
				fa=false;
			}
			else if(f[i][2]!=0) fa=false;
		}
		if(n==2){
			for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
			if(j!=i) ans=max(ans,f[1][i]+f[2][j]);
			cout<<ans;
		}
		else 
		{
		dfs(1);
			cout<<ans<<endl;
			ans=0;
		}
	}
	return 0;
}