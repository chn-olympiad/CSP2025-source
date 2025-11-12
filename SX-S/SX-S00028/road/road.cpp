#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+2;
int n,m,k,fa[N],ans;
struct node{
	int a,b,c;
}w[1000005];
bool cmp(node x,node y){
	return x.c<y.c;
}
int fd(int x){
	if (fa[x]==x)return x;
	return fa[x]=fd(fa[x]);
}
void tr(){
	for (int i=1;i<=n;i++)fa[i]=i;
	sort(w+1,w+1+m,cmp);
	for (int i=1;i<=m;i++){
		int af=fd(w[i].a);
		int bf=fd(w[i].b);
		if (af!=bf){
			ans+=w[i].c;
			fa[af]=bf;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		w[i].a=x,w[i].b=y,w[i].c=z;
	}
	tr();
	if (k==0){
		cout<<ans<<'\n';
		exit(0);
	}
	bool bl=1;
	for (int i=1;i<=k;i++){
		int x;
		cin>>x;
		bl=0;
		for (int j=1;j<=n;j++){
			cin>>x;
			if (x)bl=0;
		}
	}
	if (bl)cout<<0<<'\n';
	return 0;
}
/*
7 9 0
1 2 9
2 3 8
1 3 7
3 4 5
1 4 6
1 5 3
3 5 2
5 6 4
5 7 1
*/