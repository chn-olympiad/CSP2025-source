#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
int n,m,tmp,ans,ansx,ansy;
inline void fre()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
void dfs(int x,int y,int cnt)
{
	if(cnt==ans) 
	{
		ansx=x;
		ansy=y;
		return;
	}
	if(y&1) 
	{
		if(x<n) dfs(x+1,y,cnt+1);
			else dfs(n,y+1,cnt+1);
	}
		else
		{
			if(x>1) dfs(x-1,y,cnt+1);
				else dfs(1,y+1,cnt+1);
		}
	return;
}
int main()
{
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>tmp;
	for(int i=2;i<=n*m;i++) 
	{
		int x;
		cin>>x;
		if(x>tmp) ans++;
	}
	ans++;
	dfs(1,1,1);
	cout<<ansy<<" "<<ansx<<'\n';
	return 0;
}