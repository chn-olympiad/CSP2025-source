#include<bits/stdc++.h>
using namespace std;
int const MAXN=1e6+16;
int n,ans;
int a[MAXN],pro[MAXN];
map<string,bool>mp;
void dfs(int x,int xuan,int maxn,int sum){
	if(x>n+1)return ;
	if(xuan>=3&&maxn*2<sum){
		string s="";
		for(int i=1;i<=xuan;i++)s+=pro[i]+'0';
		if(mp[s]==0)
		{
			ans++,mp[s]=1;
			//for(int i=1;i<=xuan;i++)cout<<pro[i];
			//cout<<" "<<maxn<<" "<<sum<<"\n";
		}
	}	
	pro[xuan+1]=x;
	dfs(x+1,xuan+1,a[x],a[x]+sum);
	dfs(x+1,xuan,maxn,sum);
	//pro[1]=a[x];
	//dfs(x+1,1,a[x],a[x]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
