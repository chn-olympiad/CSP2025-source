#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e3+10;
const int mod=998244353;
int n,m;
string s1;
int s[maxn];
int c[maxn];
ll ans=0;
bool v[maxn];
int q[maxn];
bool check(){
	int cnt=0;
	int e=0;
	for(int i=1; i<=n; i++){
		int j=q[i];
		if(cnt<c[j]){
			if(s[i]==0) cnt++;
			else e++;
		}
		else cnt++; 
	}
	if(e>=m) ans=(ans+1)%mod;
} 
void dfs(int k){
	if(k>n){
		check();
		return;
	}
	for(int i=1; i<=n; i++)
		if(!v[i]){
			q[k]=i;
			v[i]=1;
			dfs(k+1);
			v[i]=0;
		}
} 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1; i<=n; i++) s[i]=s1[i-1]-'0';
	for(int i=1; i<=n; i++) cin>>c[i];
	bool flaga=1;
	for(int i=1; i<=n; i++)
		if(s[i]==0){
			flaga=0;
			break;
		} 
	dfs(1);
	cout<<ans;
	return 0;
}

