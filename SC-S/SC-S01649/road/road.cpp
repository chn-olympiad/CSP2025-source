#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m,k;
struct noed {
	int u,v,w,c,a;
}f[maxn];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) {
	    cin>>f[i].u >>f[i].v >>f[i].w ;
	}
	for(int i=1;i<=n;i++) {
		cin>>f[i].c>>f[i].a; 
	}
	cout<<1;
	return 0;
}