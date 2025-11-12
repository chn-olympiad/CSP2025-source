#include<bits/stdc++.h>
#define int long long
#define N 10010
#define pll pair <int,int>
using namespace std;
const int M=1e6+10;
struct node {
	int u,v,w;
}a[M];
bool cmp (node h,node i){
	return h.w<i.w;
}
int n,m,ans;
int k,x; //Æ­·ÖÓÃµÄ¡£¡£ 
bool f[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1; i<=m; i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	while (k--){
		cin>>x;
		for (int i=1; i<=n; i++){
			cin>>x;
		}
	}
	sort (a+1,a+1+n,cmp);
	for (int i=1; i<=m; i++){
		if (f[a[i].u] && f[a[i].v]){
			break;
		}
		ans+=a[i].w;
		f[a[i].u]=1; f[a[i].v]=1;
	}
	cout<<ans;
	return 0;
}
