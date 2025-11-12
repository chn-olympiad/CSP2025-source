#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,f,mi[20]={1e9},mi2[20],mii[20];
int u[1000010],v[1000010],w[1000010],c[110],a[20][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i]; 
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]<mi[i]){
				mi2[i]=mi[i];
				mi[i]=a[i][j];
				mii[i]=j;
			}
		}
	}
	for(int i=1;i<=n;i++){
		t=1e9;
		for(int j=1;j<=m;j++){
			if(u[j]==i||v[j]==i){
				t=min(t,w[j]);
			}
		}
		for(int j=1;j<=k;j++){
			if(i!=mii[j]){
				t=min(t,mi[j]+a[j][i]+c[j]);
			}else{
				t=min(t,mi[j]+mi2[j]+c[j]);
			}
		}
		f=f+t;
	}
	cout<<f-1;
	return 0;
}