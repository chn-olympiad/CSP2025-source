//CSP-S
//SN-S00197
//张之奇
//西安市铁一中学

#include <bits/stdc++.h>
using namespace std;

const int maxn=505;
const int mod=998244353;
int n,m;
int ans;
int c[maxn];
int a[maxn],vis[maxn];
string s;

void dfs(int k){
	if (k==n+1){
		int cnt=0;
		for (int i=1;i<=n;i++){
			if (c[a[i]]<=cnt)	cnt++;
			else if (s[i-1]=='0')	cnt++;
		}
		if (n-cnt>=m)	ans++;
	}
	for (int i=1;i<=n;i++){
		if (vis[i]==0){
			vis[i]=1;a[k]=i;
			dfs(k+1);
			vis[i]=0;a[k]=0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++)	cin>>c[i];
	dfs(1),cout<<ans;
	return 0;
}
