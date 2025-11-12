#include<bits/stdc++.h>
using namespace std;
int t[10005],n,m,k,v[10005];
long long mi=1e18;
struct nm{
	int u,v,w;
}a[1000005];
int cmp(nm l,nm r){
	return l.w<r.w;
}
void solve1(){
	long long cnt=0;
	for(int i=1;k<=n-1;i++){
		if(t[a[i].u]&&t[a[i].v])continue;
		t[a[i].u]=t[a[i].v]=1;
		k++;
		cnt+=a[i].w;
	}cout<<min(mi,cnt);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		long long sum=c;
		for(int j=1;j<=n;j++){
			cin>>v[j];
			sum+=v[j];
		}mi=min(mi,sum);
	}sort(a+1,a+1+m,cmp);
	solve1();
	return 0;
} 