#include<bits/stdc++.h>
using namespace std;
#define end '\n'
#define ll long long 
#define int long long 
const int N = 1000005;
struct node{
	int a, b, c;
}tr[N];

int n,m,k;
int fa[N];
int find(int x){
	return x==fa[x] ? x : fa[x]=find(fa[x]);
}
void init(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
} 

int merge(int a, int b) {
	int f1 = find(a), f2 = find(b);
	if(f1==f2) return false;
	
	fa[f1]=f2;
	return true;
	
}

void solve () {
	cin >>n >> m>>k;
	init();
	for(int i=1; i <=m;i++) {
		int a ,b,c;
		cin>>a>>b>>c;
		tr[i]={a,b,c};
	}
	cin >> k;
	for(int i = 1; i <= k; i++ ){
		int x;
		cin >> x;
		for(int j = 1, w1;j <= n; j++) {
			cin >> w1;
		}	
	}
	int ans = 0;
	sort(tr+1,tr+n+1,[](node a, node b){
		return a.c < b.c;
	});
	
	for(int i =1;i<=m;i++){
		int f1 = tr[i].a;
		int f2 = tr[i].b;
		if(merge(f1,f2)) ans +=tr[i].c;
	}
	cout <<ans<<endl;
	
}

signed main() {
	
	ios::sync_with_stdio(0),cin.tie(0);	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t = 1;
	while(t --) solve();
	
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/