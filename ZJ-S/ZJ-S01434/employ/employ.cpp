#include<bits/stdc++.h>
#define ll long long 
using namespace std;
bool cans[100010];
int res[100010];
bool vis[100010];
int cnt = 0;
int a,b; 
void dfs(int round, int fails, int n, int ths, int m){
	
	if(cans[round]==0 || res[ths]<=fails) fails++;
	else m++;
//	cout << round << " " << fails << " " << n << " " << ths << " " << m << endl;
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i] = 1;
		dfs(round+1,fails,n,i,m);
		vis[i] = 0;
	}if(round==n){
		if(m>=b) ++cnt, cnt %= 998244353 ;
		return ;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> a >> b;
	for(int i=1;i<=a;i++){
		char s; cin >> s; cans[i] = s-'0';
	}for(int i=1;i<=a;i++) cin >> res[i];
	cans[0] = 1; res[0] = 100000;
	dfs(0,0,a,0,-1);
	cout << cnt;
	return 0;
}
