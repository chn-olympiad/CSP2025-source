#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
struct bl{
	int t,w;
};
int n,m,k;
vector<bl>v[N];

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int wl[N];
	for(int i=1,aa,bb,cc;i<=m;i++){
		scanf("%d%d%d",&aa,&bb,&cc);
		v[bb].push_back({aa,cc});
		v[aa].push_back({bb,cc});
		wl[i]=cc;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)cin>>m;
	}
	sort(wl+1,wl+m+1);
	int su=0;
	for(int i=1;i<n;i++)su+=wl[i];
	cout<<su;
	return 0;
}