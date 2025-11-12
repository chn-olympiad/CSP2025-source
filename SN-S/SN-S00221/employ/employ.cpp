#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e2+10,mod=998244353;
int n,m,c[MAXN],fac[MAXN],len;
int pl[MAXN],flag[MAXN],ans;
char s[MAXN];
void dfs(int x){
	if(x>n){
		int num=0;
		for(int i=1;i<=n;i++){
			if(num>=c[pl[i]]){
				num++;
				continue;
			}
			if(s[i]=='0'){
				num++;
				continue;
			}
		}
		if(n-num>=m) ans++;
		return ; 
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			pl[x]=i,flag[i]=1;
			dfs(x+1);
			flag[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	if(n<=10){
		dfs(1);
		cout<<ans<<"\n";
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cout<<"0\n";
				return 0;
			}
		}
		cout<<fac[n]<<"\n";
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				cout<<fac[n]<<"\n";
				return 0;
			}
		}
		cout<<"0\n";
		return 0;
	}
	return 0;
}
