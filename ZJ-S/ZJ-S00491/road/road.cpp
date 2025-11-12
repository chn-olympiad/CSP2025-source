#include<bits/stdc++.h>
using namespace std;

int a[10010];

struct rd{
	int x, y, f;
}rds[10000010];

bool cmpf(rd a, rd b){
	return a.f < b.f;
}

int getr(int f){
	if(f==a[f]) return f;
	a[f] = getr(a[f]);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n, m, k;cin >> n >> m >> k;
	for(int i=1; i<=n; i++) a[i] = i;
	//for(int i=1; i<=n; i++) cout << getr(a[i]) << ' ';
	//cout << '\n';
	int sum = 0;
	if(k==0){
		for(int i=1; i<=m; i++) cin >> rds[i].x >> rds[i].y >> rds[i].f;
		sort(rds+1, rds+1+n, cmpf);
		for(int i=1; i<=m; i++){
			int px = getr(rds[i].x);
			int py = getr(rds[i].y);
			//cout << rds[i].x << ' '<< rds[i].y << ' '<< px << ' '<< py << ' ';
			if(px == py) continue;
			if(a[rds[i].x]==rds[i].x) n--;
			a[px] = py;
			sum += rds[i].f;
			if(n==1){
				cout << sum;
				return 0;
			}
		}
	}
	
	return 0;
}
