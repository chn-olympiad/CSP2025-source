#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e5+10;
const int mod=98244353;
int n,m;
bool f[510];
string s;
int c[510],A,g[510][510],a[510],cnt;
bool check(int k){
	int sum=0,ans=0,num;
	for(int i=0;i<k;i++){
		if(a[i]>sum&&s[i]=='1') ans++; 
		if(s[i]=='0') sum++;
		num=num*10+a[i];
	}
	return ans>=m; 
} 
void dfs(int x){
	if(x==n){
		if(check(n)==1){
			cnt++;
			cnt=(cnt%mod+mod)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			a[x]=c[i];
			dfs(x+1);
			a[x]=0;
			f[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1') A=1;
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0) tot++;
	}
	if(tot<m){
		cout<<0;
		return 0;
	}
	if(A==0){
		g[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				g[i][j]=g[i-1][j]+g[i-1][j-1];
				g[i][j]=(g[i][j]%mod+mod)%mod;
			}
		} 
		sort(c+1,c+n+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=0) ans++;
		}
		if(ans>=m){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*g[n-i+1][1]%mod+mod)%mod;
			}
		}else{
			cout<<0;
		}
		return 0;
	}
	dfs(0);
	cout<<(cnt%mod+mod)%mod;
	
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


3 2
101
1 1 2
*/
