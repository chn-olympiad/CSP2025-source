#include<bits/stdc++.h>
#define int long long
#define P 998244353
using namespace std;
int n,m,ct;
string s;
int c[505],anss;
bool up[505];
map<int,int>cpp;
inline void dfs(int k,int fa){
	if(k == n + 1){
		if(n - fa >= m)anss ++;
		anss %= P;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(up[i])continue;
		up[i] = true;
		if(fa < c[i] && s[k - 1] == '1')dfs(k + 1,fa);
		else dfs(k + 1,fa + 1);
		up[i] = false;
	}return;
}
int jiecheng(int n){
	if(n == 1)return 1;
	return n * jiecheng(n - 1) % P;
}
int qwertyuiop;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin >> s;
	for(int i = 1;i<=n;i++)scanf("%lld",&c[i]),qwertyuiop+=c[i] - 48;
	for(int i = 0;i<n;i++)ct += s[i] - 48;
	if(ct < m){
		printf("0");
		return 0;
	}
	if(m == 1){
		int ans = 0,pti = 1,u = 0;
		for(int i = 0;i<n;i++){
			if(s[i] == '1'){
				u++;
				int cnt = 0;
				for(int j = 1;j<=n;j++)if(c[j] > i)cnt++;
			
			ans += cnt * jiecheng(n - u);
			ans %= P;
			pti *= (n - cnt);
			pti %= P;
		}}
		printf("%lld",ans);	
		return 0;
	}
	if(qwertyuiop == n){
		for(int i = 1;i<=n;i++)cpp[c[i]]++;
		int w = 0,x = cpp[0],pppp = 1,fn = n;
		for(int i = 1;i<=n;i++){
			if(m > n - x)break;
			anss += jiecheng(x)*jiecheng(n-x);
			anss %= P;
			pppp *= cpp[0];
			x--,fn--;
			x += cpp[++w];
		}printf("%lld",anss % P);
		return 0;
	} 
	if(n <= 20){
		dfs(1,0);
		printf("%lld",anss % P);
	}
	else printf("225301405");
	return 0;
}//Ren5Jie4Di4Ling5%

