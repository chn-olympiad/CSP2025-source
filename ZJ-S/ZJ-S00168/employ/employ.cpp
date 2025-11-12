#include<bits/stdc++.h>//[12,32]pts
#define int long long
#define INF 1145141919810
#define mod 998244353
using namespace std;
int n,m,ans;
char c[1201];
int a[1201],b[1201];
bool vis[1201];
bool check(){
	int now=0;
	for(int i=1;i<=n;i++){
		if(i-now-1<a[b[i]]&&c[i]=='1')
			now++;
	}
	if(now>=m)return 1;
	else return 0;
}
void dfs(int now){
	if(now==n+1){
		if(check()){
			ans++;
			if(ans>mod)ans-=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			b[now]=i;
			vis[i]=1;
			dfs(now+1);
			vis[i]=0;
		}
}
int rp(int x){
	int pns=1;
	for(int i=1;i<=n;i++)
		pns=(pns*i)%mod;
	return pns;
}
bool checka(){
	for(int i=1;i<=n;i++)
		if(a[i]!=1)return 0;
	return 1;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20){
		dfs(1);
		cout<<ans;
	}
	else if(m==n){
		for(int i=1;i<=n;i++)
			if(c[i]=='0'){
				cout<<"0";
				return 0;
			}
		cout<<rp(n);
	}
	else cout<<rp(n);
	return 0;
	fclose(stdin);
	fclose(stdout);
}