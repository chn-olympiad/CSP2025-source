#include <bits/stdc++.h>
using namespace std;

int const N=510,p=998244353;
int n,m,res,c[N];
string s;
bool sp=1,t[N],vis[N];
bool tst[N];

void dfs(int x,int w){
	//cout<<x<<' '<<w<<'\n';
	for (int i=1;i<=n;i++){
		if (vis[i]) continue;
		vis[i]=1;
		int cnt=0;
		for (int j=1;j<x;j++){
			if (!tst[j]) cnt++;
		}
		if (x==n){
			if (cnt<c[i]) w++;
			if (w>=m) res++,res%=p;
			vis[i]=0;
			return;
		} 
		if (cnt<c[i] && t[x]){
			tst[x]=1;
			dfs(x+1,w+1);
		}
		else{
			tst[x]=0;
			dfs(x+1,w);
		}
		tst[x]=0,vis[i]=0;
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s; 
	
	s=" "+s;
	for (int i=1;i<=n;i++){
		t[i]=s[i]-'0';
		sp&=t[i];
	}
	
	for (int i=1;i<=n;i++) cin>>c[i];
	if (sp){
		cout<<'0';
		return 0;
	}
	dfs(1,0);
	cout<<res;
	
	return 0;
}
