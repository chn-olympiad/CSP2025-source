#include<bits/stdc++.h>
using namespace std;
int a[1005];
map<string,int>mp;
int n,m;
string s;
long long cnt;
bool vis[1005];
void dfs(int x,int tp,int op){
	if(tp>=m){
		long long ans=1;
		for(int i=2;i<=n-x;i++){
			ans*=i;
		}
		cnt=(cnt+ans)%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(op>=a[i]||s[x]=='0'){
				dfs(x+1,tp,op+1);
			}else{
				dfs(x+1,tp+1,op);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<cnt;
	return 0;
}
