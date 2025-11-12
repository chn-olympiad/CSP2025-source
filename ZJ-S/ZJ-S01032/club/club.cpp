#include<bits/stdc++.h>
using namespace std;
int n,h,mx;
struct club
{
	int a,b,c;
}p[100005];
int ru[114514];
void dfs(int a,int b,int c,int i)
{
	if(a>h||b>h||c>h)
	{
		return;
	}
	//分配的新人过多
	if(i>n+1)
	{	int k=0;
		for(int i=1;i<=n;++i)
		{
			k+=ru[i];
	}
		mx=max(mx,k);
		return;
	}
	ru[i]=p[i].a;
	dfs(a+1,b,c,i+1); 
	ru[i]=p[i].b;
	dfs(a,b+1,c,i+1); 
	ru[i]=p[i].c;
	dfs(a,b,c+1,i+1); 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		h=n/2,mx=-1;
		for(int i=1;i<=n;++i)
		{
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		dfs(0,0,0,1);
		cout<<mx<<endl;
	}
	return 0;
}
