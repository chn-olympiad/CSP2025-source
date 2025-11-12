#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct cmp{
	int u,v,w; 
}a[1000005];
int c[20],cun[20][100005];
bool nmp(cmp a,cmp b){
	return a.w<=b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	int f=0;
	int minn=1e9+10;
	int minnn=1e9+10;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		minn=min(minn,c[i]);
		if(c[i]!=0){
			f=1;
		}
		for(int j=1;j<=n;j++){
			cin>>cun[i][j];
			minnn=min(minnn,cun[i][j]);
			if(cun[i][j]!=0){
				f=1;
			}
		}
	}
	if(k==0){
		long long ans=0;
		sort(a+1,a+1+m,nmp);
		for(int i=1;i<n;i++){
			ans+=a[i].w;
		}
		cout<<ans<<endl;
	}else if(f==0){
		cout<<0<<endl;
	}else{
		long long ans=0;
		sort(a+1,a+1+m,nmp);
		for(int i=1;i<n;i++){
			ans+=a[i].w;
		}
		if(n>=m){
			ans+=minn;
			ans+=minnn;
		}
		cout<<ans<<endl;
	}
	return 0;
}