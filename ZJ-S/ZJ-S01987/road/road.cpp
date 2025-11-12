#include<bits/stdc++.h>

using namespace std;
const int N=1e6+10;
struct ro{
	int u,v,w;
}rp[N];
int n,m,k,ans,a[15][N],c[15][1005][1005];
bool cmp(ro xx,ro yy){
	return xx.w >yy.w ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>rp[i].u >>rp[i].v >>rp[i].w ;
		ans+=rp[i].w ;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++){
//			for(int p=1;p<=n;p++){
//				c[i][j][p]=a[i][j]+a[i][p];
//			}
//		}
//	}
	sort(rp+1,rp+1+m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			if(a[j][rp[i].u ]+a[j][rp[i].v ]+a[j][0]<=rp[i].w ){
				ans-=rp[i].w;
				ans+=a[j][rp[i].u ]+a[j][rp[i].v ]+a[j][0];
				a[j][rp[i].u ]=a[j][rp[i].v ]=a[j][0]=0;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
