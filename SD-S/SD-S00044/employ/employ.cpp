#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1000;
const int mod=998244353;
int n,m,cnt,ans=1,tot;
int vis[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		int t=c-'0';
		if(t==1) cnt++;
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		if(vis[t]==0){
			vis[t]=1;
			tot++;
		}
	}
	if(tot<=cnt) cout<<cnt%mod;
	else{
		for(int i=cnt;i>=2;i--){
			ans*=i;
		}
		cout<<ans%mod;
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}

