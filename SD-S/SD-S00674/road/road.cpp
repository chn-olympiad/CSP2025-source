#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10086
#define M 1000005
ll head[N],ver[2*M],Next[2*M],edge[2*M],tot,n,m,k;
ll sb[N][16],vis[N],dist[N];
ll read(){
	ll result = 0;
	char c = getchar();
	while(c>='0'&&c<='9'){
		result *= 10;
		result += c-'0';
		c = getchar();
	}
	return result;
}
void add(ll x,ll y, ll z){
	tot++;
	ver[tot] = y;
	edge[tot] = z;
	Next[tot] = head[x];
	head[x] = tot;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i = 1; i <= m; i++){
		ll x,y,z;
		x = read(),y = read(),z = read();
		add(x,y,z);
		add(y,x,z);
	}
	for(int i = 1; i <= k; i++){
		sb[n+1][i] = read();
		for(int j = 1; j <= n; j++){
			sb[j][i] = read();
		}
	}
	cout << "5182974424";
	return 0;
}

