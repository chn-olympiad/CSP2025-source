#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 1e4+10;
int n,m,k;
int c[15];
int a[15][maxn];
struct node{
	int a,b,c;
}p[1000010];
int f[maxn];
int find(int x) {
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
bool cmp(node x,node y) {
	return x.c < y.c;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i) {
		f[i]=i;
	}
	for(int i=1;i<=m;++i) {
		scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
	}
	bool f1=0;
	for(int i=1;i<=k;++i) {
		scanf("%d",&c[i]);
		if(c[i] == 0) f1=1;
		for(int j=1;j<=n;++j) {
			scanf("%d",&a[i][j]);
			if(a[i][j] == 0) f1=1;
		}
	}
//	cout << n << " " << m << " " << k << "\n"; 
//	for(int i=1;i<=m;++i) {
//		cout << p[i].a << " " << p[i].b << " " << p[i].c << "\n";
//	}
	 
	sort(p+1,p+1+m,cmp);
	ll ans=0;
	for(int i=1;i<=m;++i) {
		int fa=find(p[i].a),fb=find(p[i].b);
		if(fa ^ fb) {
			f[fa]=fb;
			ans += p[i].c;
		}
	}
	printf("%lld\n",ans);
	 // 16 points
	return 0;
}

/*
4 4 0
1 4 6 
2 3 7
4 2 5 
4 3 4 
1 1 8 2 4
100 1 3 2 4

*/
