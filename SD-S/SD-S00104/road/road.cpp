#include<bits/stdc++.h>
using namespace std;

//#define int long long
const int N = 1000005;

int n ,m ,k;

struct edge{
	int u,v,w;
}e[N];
int f[1005];
int a[15][1005];
int c;
bool cmp(edge a,edge b){
	return a.w < b.w;
}
int find(int x){
	if(f[x] == x){
		return x;
	}
	else{
		
		return f[x] = find(f[x]);
	}
}

void krus(){
	sort(e+1,e+1+m,cmp);
	int ans = 0;
//	f[e[1].v] = e[1].u;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt == n-1){
			break;
		}
		if(f[e[i].v] == f[e[i].u]){
			continue;
		}
		ans += e[i].w;
		
	    f[e[i].v] = find(e[i].u);
		cnt++;
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		f[i] = i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	int cntm = m;
	if(k==0){
		krus();
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin >> c;
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			
		}
		for(int j=1;j<=n;j++){
			if(c==0 && a[i][j] == 0){
				for(int d=1;d<=n;d++){
					if(d == j) continue;
					e[++cntm].u = j;
					e[cntm].v = d;
					e[cntm].w = a[i][d];
				}
			}
		}
	}
	krus();
	return 0;
	
	
	
//	for(int i=1;i<=n;i++){
//		cout << f[i] << ' ';
//	}
	
//	cout << "\n";
//	
//	for(int i=1;i<=m;i++){
//		int u,v,w;
//		cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << "\n";
//	}
	return 0;
}


