#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int f[1000006];
int find(int x){
	if(f[x]==x) return x;
	return find(f[x]);
}
void he(int x,int y){
	f[find(x)]=find(y);
	return;
}
struct Edge{
	int u,e,val;
}E[11000005];
bool cmp(Edge x,Edge y){
	return x.val<y.val;
}
void work1(){//CCF is so good!
	for(int i=1;i<=m;i++) cin>>E[i].u>>E[i].e>>E[i].val;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(E+1,E+1+m,cmp);
	int ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		int u=E[i].u,e=E[i].e;
		if(find(u)==find(e)) continue;
		he(u,e);cnt++;ans+=E[i].val;
		if(cnt==n-1){
			cout<<ans<<endl;
			return;
		}
	}
}
int vil[15][1005];
void work2(){//CCF is so good!
	for(int i=1;i<=m;i++) cin>>E[i].u>>E[i].e>>E[i].val;
	for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int j=1;j<=n;j++) cin>>vil[i][j];
	}
	for(int c=1;c<=k;c++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				E[++m].e=i;
				E[m].u=j;
				E[m].val=vil[c][i]+vil[c][j];
				if(m%1000000==0) cout<<m<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(E+1,E+1+m,cmp);
	long long ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		int u=E[i].u,e=E[i].e;
		if(find(u)==find(e)) continue;
		he(u,e);cnt++;ans+=E[i].val;
		if(cnt==n-1){
			cout<<ans<<endl;
			return;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)work1();
	else work2();
	return 0;
}
/*
6 9 0
1 2 3
2 3 1
3 4 5
4 5 9
5 6 8
2 6 4
3 5 7
2 4 4
1 6 2*/
