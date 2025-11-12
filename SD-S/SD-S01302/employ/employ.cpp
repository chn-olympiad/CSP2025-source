#include <bits/stdc++.h>
using namespace std;

const int N=510;
const int mod=998244353;

int n,m;
string s;
int p[N],a[N];
int ans,cnt;
bool vis[N];

void dfs(int i,int k){
	if(i==n+1){
		if(k>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int j=1;j<=n;j++){
		if(!vis[j]){
			vis[j]=true;
			if(s[i-1]=='0') dfs(i+1,k);
			else {
				if(a[j]<i-k) dfs(i+1,k);
				else dfs(i+1,k+1);
			}
			vis[j]=false;
		}
	}
}

int main (){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		p[i]=p[i-1]+s[i-1]-'0';
	}
	
	dfs(1,0);
	
	cout << ans;
	
	return 0;
}
