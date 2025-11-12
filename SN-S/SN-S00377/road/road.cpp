#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=INT_MAX;
struct road {
	long long u,v,w;
};
struct village {
	long long c;
};
bool cmp(road a,road b) {
	return a.w<b.w;
}
long long a[10][10001];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	village v[10];
	road r[m+n]={0,0,0};
	int V;
	for(long long i=0; i<n; i++)
		cin>>r[i].u >>r[i].v>>r[i].w;
	for(long long i=0; i<k; i++) {
		cin>>v[i].c;
		for(long long j=1; j<=n; j++)
			cin>>a[i][j];
	}
	for(int i=0;i<k;i++){
		long long b=ans;
		ans=min(ans,v[i].c);
		if(ans!=b)V=i;
	}
	for(int j=1; j<=n; j++)
		r[m+j]={n+1,j,a[V][j]};
	sort(r,r+m+n,cmp);
	for(int i=0;i<n+k-1;i++)
		ans+=r[i].w;
	cout<<ans;
	return 0;
}

