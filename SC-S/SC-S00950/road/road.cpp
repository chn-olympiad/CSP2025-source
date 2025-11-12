#include<bits/stdc++.h>
using namespace std;
long long u,v,w,sw[1000002],ans,c,n,m,k,a[1002][1002];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=1e11;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
		ans+=w;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][k]+a[k][j]>=a[i][j]&&a[i][j]<1e11){
					ans-=a[i][j];
					a[i][j]=1e11;
				}
			}
		}
	}
	cout<<abs(ans);
	return 0;
}
/*
距离考试结束：00:41:56
不会写，瞎写一个弗洛伊德，反正也是图论的 
距离考试结束：00:27:06
交完了就冬眠吧 
*/