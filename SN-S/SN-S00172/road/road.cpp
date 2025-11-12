#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,c;
	cin>>n>>m>>k;
	int u[m+1],v[m+1],w[m+1],a[k+1],min_=n,minn;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<=m;j++){
			if (u[j]<min_){
				min_=u[j];
				minn=j;
			}
		}
		c+=min_;
		u[minn]=n;
		minn=n;
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
