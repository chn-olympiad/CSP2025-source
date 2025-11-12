//40pts
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
#define int long long
const int MOD=998244353;
int a[5555],n,maxn,dfdfdf;
bool vis[323232];
void dfs(int x,int y,int z,vector<int> l){
	if(x==y){
		int ans=0,ans2=0;
		for(int i=0;i<l.size();i++) ans=max(ans,l[i]),ans2+=l[i];
		if(ans2>ans*2) dfdfdf++;
		while(dfdfdf>=MOD) dfdfdf-=MOD;
		return;
	}
	for(int i=z;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			vector<int> h=l;
			h.push_back(a[i]);
			dfs(x+1,y,i,h);
			vis[i]=0;
		}
	}
}
signed main(){
	ifstream in("polygon.in");
	ofstream out("polygon.out");
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	in>>n; 
	for(int i=1;i<=n;i++) in>>a[i],maxn=max(maxn,a[i]);
	if(maxn==0){
		out<<0;
		return 0;
	}else if(maxn==1){
		int h=0; 
		for(int i=1;i<=n;i++){
			if(a[i]) h++;
		}
		int ans=1;
		int g=h*n;
		while(g>=MOD) g-=MOD;
		g*=(n-1);
		while(g>=MOD) g-=MOD;
		ans+=g;while(ans>=MOD) ans-=MOD;
		out<<ans;
		return 0;
	}else{
		dfdfdf=0;
		for(int i=3;i<=n;i++){
			vector<int> k;
			dfs(0,i,1,k);
		} 
		out<<dfdfdf;
	} 
	return 0;
}
