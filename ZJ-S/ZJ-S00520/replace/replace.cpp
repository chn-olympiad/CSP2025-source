#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,q;
string a,b;
map<pair<string,string> , int> mp;
map<pair<string,string> , int> mpp;
string pd,pf;
int le=0;
int mi=-1,mx=-1;
int ans=0;
string ym,wm;
void dfs(int l,int r,string yyw,string wyy,int rx,int lx)
{
	if(mp[pair<string,string>{yyw,wyy}]==1&&mpp[pair<string,string>{yyw,wyy}]!=1)
	{
		mpp[pair<string,string>{yyw,wyy}]=1;
		ans++;
	}
	if(l==lx&&r==rx)
	{
		if(l!=0)
		{
			dfs(l-1,r,pd[l-1]+yyw,pf[l-1]+wyy,rx,lx);
		}
		if(r!=le-1)
		{
			dfs(l,r+1,yyw+pd[r+1],wyy+pf[r+1],rx,lx);
		}
	}else{
		if(l!=0)
		{
			dfs(l-1,r,pd[l-1]+yyw,pf[l-1]+wyy,rx,lx);
		}
		if(r!=le-1)
		{
			dfs(l,r+1,yyw+pd[r+1],wyy+pf[r+1],rx,lx);
		}
	}
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		mp[pair<string,string>{a,b}]=1;
	}
	for(int i=1;i<=q;i++)
	{
		mpp.clear();
		mi=mx=-1;
		cin>>pd>>pf;
		le=pd.size();
		for(int j=0;j<le;j++)
		{
			if(pd[j]!=pf[j])
			{
				if(mi==-1)
				{
					mi=j;
				}
				mx=j;
			}
		}
		ym=wm="";
		for(int j=mi;j<=mx;j++)
		{
			ym+=pd[j];
			wm+=pf[j];
		}
		ans=0;
		dfs(mi,mx,ym,wm,mx,mi);
		cout<<ans<<'\n';
	}
	return 0;
}

