#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=550;
const int mod=998244353;
int n,m,c[N];
ll fc[N];
string s;
bool vis[N];
int a[N],tot;
int ans=0;
void dfs(int x,int sum){
	if(sum>n-m) return;
	if(x==n+1){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x]=i;
			if(s[x-1]=='0') sum++;
			else if(sum>=c[i]) sum++;
			dfs(x+1,sum);
			vis[i]=0;
			if(s[x-1]=='0') sum--;
			else if(sum>=c[i]) sum--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	int f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1') f=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]) cnt++;
	}
	
		
	
	if(n==m){
		if(!f||cnt!=n){
			cout<<0;
		}else{
			fc[1]=1;
			for(int i=2;i<=cnt;i++){
				fc[i]=(1ll*i*fc[i-1])%mod;
			}
			cout<<fc[cnt]%mod;
		}
		return 0;
	}
	dfs(1,0);
	cout<<ans;

	return 0;
}

