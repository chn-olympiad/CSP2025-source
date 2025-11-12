#include<bits/stdc++.h>
using namespace std;
int n,k=3,ans=0;
int st[25];
int df[25];
bool fdf[25];
bool flag=1;
void dfs(int p){
	if(p==k+1){
		bool f=1;
		int mx=df[1],su=df[1];
		for (int x=2;x<=k;x++){
			mx=max(mx,df[x]);
			if(df[x]<df[x-1]){
				f=0;
			}
			su+=df[x];
		}
		if(f&&su>2*mx){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for (int x=p;x<=n;x++){
		if(!fdf[x]){
			df[p]=st[x];
			fdf[x]=1;
			dfs(p+1);
			fdf[x]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int x=1;x<=n;x++){
		cin>>st[x];
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	sort(st+1,st+n+1);
	for (k=3;k<=n;k++){
		dfs(1);
	}
	cout<<ans;
	return 0;
}
