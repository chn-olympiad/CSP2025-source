#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second
#define pb emplace_back

const int N=710,mod=998244353;

int n,m,c[N],jc[N],b[N],ans,op[N];

string s;

void check(){
	int k=0,ye=0;
	for(int i=1;i<=n;i++){
		if(s[op[i]-1]=='0'){
			k++;continue;
		}
		else if(k>=c[op[i]]){
			k++;continue;
		}
		else ye++;
	}
	if(ye>=m)ans++;
}

void dfs(int p){
	if(p==n+1){
		check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			op[p]=i;
			b[i]=1;
			dfs(p+1);
			b[i]=0;
			op[p]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;jc[0]=1;
	for(int i=1;i<=700;i++)jc[i]=jc[i-1]*i%mod;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0||s[i-1]=='0'){
				cout<<0;
				return 0;
			}
		}
		cout<<jc[n];
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans%mod;
		return 0;
	}
	cout<<0;
	return 0;
}
