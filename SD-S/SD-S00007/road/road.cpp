#include<bits/stdc++.h>
using namespace std;
int believe[10009],is_used[10009];
int a[10009][10009],u,v,w;
int n,m,k;
int minn=-1;
void qpl(int r){
	if(r==0){
		int num=a[believe[n]][1];
		int ros[10009],rp=1;
		ros[0]=a[believe[n]][1];
		for(int j=1;j<n;j++){
			num+=a[believe[j]][believe[j+1]];
			ros[rp]=a[believe[j]][believe[j+1]];
			rp++;
		}
		sort(ros,ros+rp);
		num-=ros[rp-1];
		if(minn==-1){
			minn=num;
		}else{
			minn=min(minn,num);
		}
		return;
	}
	for(int i=2;i<=n;i++){
		if(is_used[i]==false){
			believe[n+1-r]=i;
			is_used[i]=true;
			qpl(r-1);
			is_used[i]=false;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,-1,sizeof(a));
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	int x,ex[10009];
	for(int i=0;i<k;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>ex[j];
		}
		for(int j=1;j<=n;j++){
			for(int h=j+1;h<=n;h++){
				if(a[j][h]==-1){
					a[j][h]=x+ex[j]+ex[h];
				}else{
					a[j][h]=min(a[j][h],x+ex[j]+ex[h]);
				}
				a[h][j]=a[j][h];
			}
		}
	}
	believe[1]=1;
	qpl(n-1);
	cout<<minn;
	return 0;
}
