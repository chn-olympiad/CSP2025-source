#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int mod=998244353;
int n,m,use[maxn],ans,c[maxn];
string s;
void dfs(int w,int p,int fq){
	if(w==n+1){
		if(p>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(use[i]==0){
			use[i]=1;
			if(fq>=c[i]){
				dfs(w+1,p,fq+1);
			}
			else if(s[w-1]=='1'){
				dfs(w+1,p+1,fq);
			}
			else{
				dfs(w+1,p,fq+1);
			}
			use[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}
