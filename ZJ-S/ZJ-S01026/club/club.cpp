#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+3;

//other
struct xing{
	int sta;
	int stb;
	int stc;
	int number;
};
xing a[N];

int ans=0,nn;

//dfs

void dfs(int s,int n,int sa,int sb,int sc,bool seat[N][4])
{
	//cout<<s<<endl;
	if(sa+sb+sc==nn)
	{
		ans=max(ans,s);
		return;
	}
	if(sa<nn/2)
	{
		if(seat[n][1]!=1)seat[n][1]=1,dfs(s+a[n].sta,n+1,sa+1,sb,sc,seat),seat[n][1]=0;
	}
	if(sb<nn/2)
	{
		if(seat[n][2]!=1)seat[n][2]=1,dfs(s+a[n].stb,n+1,sa,sb+1,sc,seat),seat[n][2]=0;
	}
	if(sc<nn/2)
	{
		if(seat[n][3]!=1)seat[n][3]=1,dfs(s+a[n].stc,n+1,sa,sb,sc+1,seat),seat[n][3]=0;
	}
}

//main
bool sea[N][4];
int doit(int n)
{
	for(int i=1;i<=n;i++)sea[i][1]=sea[i][2]=sea[i][3]=0;
	ans=0;
	nn=n;
	int maxx=n/2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].sta>>a[i].stb>>a[i].stc;
		a[i].number=i;
	}
	dfs(0,1,0,0,0,sea);
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int n;
	cin>>n;
	int in;
	for(int i=1;i<=n;i++)
	{
		cin>>in;
		cout<<doit(in)<<endl;
	}
}
