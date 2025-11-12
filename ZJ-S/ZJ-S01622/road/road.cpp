#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[10050][10050],cnt = 1,sum,vis[10050],ans = 1e9;
void dfs(long long r){
	if(cnt == n){
		ans = min(ans,sum);
		return;
	}
	long long p = sum,q = cnt;
	for(int i = 1;i <= n+k;i++){
		if(a[r][i] != 1e9 && r != i && vis[i] == 0){
			sum += a[r][i];
			vis[i] = 1;
			if(i <= n)cnt++;
			if(i > n){
				sum += a[i][i];
			}
			dfs(i);
			sum = p;
			vis[i] = 0;
			cnt = q;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,1e9,sizeof(a));
	for(int i = 1;i <= n+k;i++){
		a[i][i] = 0;
	}
	for(int i = 0;i < m;i++){
		long long u,v,d;
		cin>>u>>v>>d;
		a[u][v] = d;
		a[v][u] = d;
	}
	for(int i = 1;i <= k;i++){
		long long p;
		cin>>p;
		a[n+i][n+i] = p;
		for(int j = 1;j <= n;j++){
			long long o;
			cin>>o;
			a[n+i][j] = o;
//			cout<<n+i<<' '<<j<<' '<<o<<endl;
		}
	}
	vis[1] = 1;
	dfs(1);
	cout<<ans+n+2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
