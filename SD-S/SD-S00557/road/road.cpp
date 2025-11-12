#include<bits/stdc++.h>

using namespace std;
int n,m,k;
int u[100005],v[100005],w[100005];
int a[100005],b[100005];
int c[20][100005];
int x[100005],y[100005];
int cnt;
int minn=1e7,minnn=1e7;
int num;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(minn<=w[i]){
			continue;
		}
		else{
			a[w[i]]=u[i];
			b[w[i]]=v[i];
		}
	}
	if(k==0){
		int ans=n--;
		sort(w+1,w+1+m);
		num=w[1];
		x[a[w[1]]]++;
		y[b[w[1]]]++;
		for(int i=2;i<=m;i++){
			if((x[a[w[i]]]==0)||(y[b[w[i]]]==0)){
				if(ans<cnt){
					break;
				}
				x[a[w[i]]]++;
				y[b[w[i]]]++;
				num+=w[i];
				cnt++;
			}
		}
		cout<<num<<'\n';
	}
	else if(k){
		for(int i=1;i<=k;i++){
			for(int j=0;j<=n;j++){
				cin>>c[i][j];
			}
			minnn=min(minnn,c[i][0]);
		}
		cout<<minnn<<'\n';
	}
	return 0;
} 
