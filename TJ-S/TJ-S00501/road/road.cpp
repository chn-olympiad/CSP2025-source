#include <iostream>
#include <cstdio>
using namespace std;
int minnmax;
int minnmax_;
int tr[1000005][4];
int cts[12][10005];
int ifhaveroad(int a,int b,int m){
	for(int i=1;i<=m;i++){
		if(tr[i][1]==a&&tr[i][2]==b){
			return tr[i][3];
		}
		else if(tr[i][1]==b&&tr[i][2]==a){
			return tr[i][3];
		}
	}
	return 0;
}
int countctsmin(int a,int b,int k){
	int minn=1e8;
	for(int i=1;i<=k;i++){
		if(cts[i][a+1]+cts[i][b+1]+cts[i][1]<minn){
			minn=cts[i][a+1]+cts[i][b+1]+cts[i][1];
		}
	}
	return minn;
}
int countmin(int a,int b,int k,int m){
	if(ifhaveroad(a,b,m)>0){
		return min(ifhaveroad(a,b,m),countctsmin(a,b,k));
	}
	else{
		return countctsmin(a,b,k);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;//城市数量、道路数量、乡镇数量 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>tr[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>cts[i][j];
		}
	}
	int minn[n]={};
	for(int i=1;i<=n;i++){
		minn[i]=1e8;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			minnmax=-1e8;
			for(int l=1;l<=n-1;l++){
				if(minn[l]>minnmax){
					minnmax=minn[l];
					minnmax_=l;
				}
			}
			if(countmin(i,j,k,m)<minnmax){
				minn[minnmax_]=countmin(i,j,k,m);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n-1;i++){
		ans+=minn[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
