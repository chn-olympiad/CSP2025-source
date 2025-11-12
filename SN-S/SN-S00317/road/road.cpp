#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0,ass1=0,ans2=0;
int u[1000005],v[1000005],w[1000005];
int j[15][10005];
int a[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		
	}
	for(int i=1;i<=k;k++){
		for(int q=1;q<=n+1;q++){
			cin>>j[i][q];
		}
	}sort(w,w+m);
	for(int i=m;i>=n-1;i--){
		ass1=ass1+w[i];
	}
	for(int i=1;i<=k;i++){
		sort(j[i][2],j[i][n+1]);
	}
	for(int i=1;i<=k;i++){
			a[i]=min(j[i][1]+j[i][n+1],j[i][1]+j[i][n]);
	
	}
	sort(a,a+k);
	ans=a[k] + ass1-w[n-1];
	cout<<min(ans,ass1);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
