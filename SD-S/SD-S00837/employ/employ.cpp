#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,f=1;
	char ch = getchar();
	while(ch<'0' || '9'<ch){
		if(ch == '-') f=-1;
		ch = getchar();
	}
	while('0'<=ch && ch<='9'){
		x = (x<<3)+(x<<1)+ch-'0';
		ch = getchar();
	}
	return x*f;
}
const int N=510,mod = 998244353;
typedef pair<int,int> pii;
int n,m;
string str;
int c[N],p[N];
int vis[N]; 
ll ans = 0;
void dfs(int pl){
	if(pl == n+1){
		int no_use = 0,us = 0;
		for(int i=1;i<=n;i++){
			if(no_use >= p[c[i]] || str[i] == '0') no_use++;
			else us++;
		}
		if(us >= m) ans++;
		ans%=m;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		p[pl] = i;
		vis[i] = true;
		dfs(pl+1);
		vis[i] = false;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read(),m = read();
	cin>>str;
	str = " "+str;
	for(int i=1;i<=n;i++){
		c[i] = read();
	} 
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}

