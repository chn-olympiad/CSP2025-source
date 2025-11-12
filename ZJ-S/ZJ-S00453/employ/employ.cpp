#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+7,mod=998244353;
int n,m,c[maxn],b[maxn],vis[maxn];
long long ans;
string s;
void dfs(int d,int w,int t){
	if(d>n){
		if(t>=m) ans=(ans+1)%mod;
		return;
	}
	if(w>n-m) return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[d-1]=='0'||c[i]<=w) dfs(d+1,w+1,t);
			else dfs(d+1,w,t+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	bool flag=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			flag=0;
			break;
		}
	}
	if(m==n){
		if(flag==0) cout<<0;
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				if(c[i]==0){
					sum++;
				}
			}
			if(sum) cout<<0;
			else{
				ans=1;
				for(int i=1;i<=n;i++) ans=ans%mod*i%mod%mod;
				cout<<ans;
			}
		}	
		return 0;
	}
	if(flag){
		sort(c+1,c+1+n);
		int sum=0;
		for(int i=1;i<=n;i++) if(c[i]==0) sum++;
		ans=1;
		for(int i=1;i<=n;i++) ans=ans%mod*i%mod%mod;
		if(sum==0) cout<<ans;
		else cout<<ans/n*(n-sum)%mod;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
