#include<bits/stdc++.h>
using namespace std;

const int MAXN=10000;
int n,m,ans,a[MAXN],b[MAXN],c[MAXN];
char s[MAXN];

void check(){
	int cnt=0,tmp=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'||c[a[i]]<=cnt) cnt++;
		else{
			tmp++;
		}
		if(tmp>=m){ans++; return;}
	}
}

void dfs(int x){
	if(x>n){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			a[x]=i, b[i]=1;
			dfs(x+1);
			b[i]=0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> s[i];
	for(int i=1;i<=n;i++) cin >> c[i];
	dfs(1);
	cout << ans;
	
	return 0;
}
