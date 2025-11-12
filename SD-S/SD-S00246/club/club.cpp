#include<bits/stdc++.h>
using namespace std;
long long int a[100010][4];
long long int df[4];
void dfs(long long int x,long long int y,long long int ca,long long int cb,long long int cc,long long int nn,long long int anss)
{
	if(y==nn)
	{
		df[x]=max(df[x],anss);
	}
	
	if(ca<nn/2)
	{
		dfs(1,y+1,ca+1,cb,cc,nn,anss+a[y+1][1]);
	}
	if(cb<nn/2)
	{
		dfs(2,y+1,ca,cb+1,cc,nn,anss+a[y+1][2]);
	}
	if(cc<nn/2)
	{
		dfs(3,y+1,ca,cb,cc+1,nn,anss+a[y+1][3]);
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long int t,n,t1,t2,t3;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	long long int ans=-1;
	while(t--)
	{
		cin>>n;
		for(long long int i=1;i<=n;i++)
		    cin>>a[i][1]>>a[i][2]>>a[i][3];
	df[1]=0;
	df[2]=0;
	df[3]=0;
	dfs(1,1,1,0,0,n,a[1][1]);
	dfs(2,1,0,1,0,n,a[1][2]);
	dfs(3,1,0,0,1,n,a[1][3]);
	t1=max(df[1],df[2]);
	t2=max(t1,df[3]);
	cout<<t2<<endl;
    }
	return 0;
 } 
 
