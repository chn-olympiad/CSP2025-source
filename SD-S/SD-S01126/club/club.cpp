#include<bits/stdc++.h>

using namespace std;

struct node{
	long long x;
	long long y;
	long long z;
	long long k;
	long long bj;
}a[100010];

node arr[100010];
long long brr[100010];

bool cmp1(node a, node b){
	return (a.x - a.y) > (b.x - b.y);
}

bool cmp2(node a, node b){
	return (a.z - a.x) > (b.z - b.x);
}

bool cmp3(node a, node b){
	return (a.z - a.k) > (b.z - b.k);
}

long long k = 0;
long long n;

void dfs(long long x, long long p, long long v){
	if(p > n / 2){
		return;
	}
	if(x == n){
		k = max(k, v);
		return;
	}
	x++;
	dfs(x, p, v + a[x].k);
	dfs(x, p + 1, v + a[x].z);
	return;
}

void dfs1(long long x, long long p1, long long p2, long long p3, long long v){
	if(p1 > n / 2 || p2 > n / 2 || p3 > n / 2){
		return;
	}
	if(x == n){
		k = max(k, v);
		return;
	}
	x++;
	dfs1(x, p1 + 1, p2, p3, v + a[x].x);
	dfs1(x, p1, p2 + 1, p3, v + a[x].y);
	dfs1(x, p1, p2, p3 + 1, v + a[x].z);
	return;
}

void f(){
	cin >> n;
	long long l = 0;
	for(long long i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
		if(a[i].z != 0){
			l = 1;
		}
	}
	if(n <= 10){
		k = 0;
		dfs1(0, 0, 0, 0, 0);
		cout << k << endl;
		return;
	}
	if(n <= 31){
		sort(a + 1, a + n + 1, cmp1);
		for(long long i = 1; i <= n; i++){
			if(i <= (n / 2)){
				a[i].k = a[i].x;
			}else{
				a[i].k = a[i].y;
			}
		}
		k = 0;
		dfs(0, 0, 0);
		cout << k << endl;
		return;
	}
	if(l == 0){
		sort(a + 1, a + n + 1, cmp1);
		for(long long i = 1; i <= n; i++){
			if(i <= (n / 2)){
				a[i].k = a[i].x;
			}else{
				a[i].k = a[i].y;
			}
		}
		long long k = 0;
		for(long long i = 1; i <= n; i++){
			k += a[i].k;
		}
		cout << k << endl;
		return;
	}
	l = 0;
	sort(a + 1, a + n + 1, cmp1);
	for(long long i = 1; i <= n; i++){
		if(i <= (n / 2)){
			a[i].k = a[i].x;
			if(a[i].y > a[i].x){
				a[i].bj = -2;
				l = -2;
			}
		}else{
			a[i].k = a[i].y;
			if(a[i].x > a[i].y){
				a[i].bj = -1;
				l = -1;
			}
		}
	}
	if(l == 0){
		long long v = 0;
		for(long long i = 1; i <= n; i++){
			if((v < (n / 2)) && ((a[i].z - a[i].k) > 0)){
				a[i].k = a[i].z;
				v++;
			}
		}
		long long k = 0;
		for(long long i = 1; i <= n; i++){
			k += a[i].k;
		}
		cout << k << endl;
		return;
	}
	if(l == -2){
		for(long long i = 1; i <= n; i++){
			long long tmp = a[i].x;
			a[i].x = a[i].y;
			a[i].y = tmp;
		}
		sort(a + 1, a + n + 1, cmp1);
	}
	long long xzz = 0;
	sort(a + 1, a + (n / 2) + 1, cmp3);
	for(long long i = 1; i <= n / 2; i++){
		arr[i] = a[i];
		if(a[i].z > a[i].x){
			a[i].k = a[i].z;
			xzz++;
		}
	}
	long long v = xzz;
	sort(arr + 1, arr + (n / 2) + 1, cmp2);
	long long p = 0;
	for(long long i = n / 2 + 1; i <= n; i++){
		if(a[i].x > a[i].y && ((a[i].z - a[i].y) <= (a[i].x - a[i].y))){
			if(xzz >= 1){
				a[i].k = a[i].x;
				xzz--;
				continue;
			}
			if(arr[p + 1].z - arr[p + 1].x - a[i].y + a[i].x > 0){
				p++;
				a[i].k = a[i].x;
			}
			continue;
		}
	}
	sort(a + n / 2 + 1, a + n + 1, cmp3);
	for(long long i = n / 2 + 1; i <= n; i++){
		if(a[i].z - a[i].y > 0 && v < n / 2){
			v++;
			a[i].k = a[i].z;
		}
	}
	long long c = 0;
	for(long long i = 1; i <= n; i++){
		c += a[i].k;
	}
	cout << c << endl;
	return;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long sj;
	cin >> sj;
	while(sj--){
		f();
	}
	
	
	
	
	return 0;
}
