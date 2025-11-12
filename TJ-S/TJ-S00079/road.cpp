#include<bits/stdc++.h>
using namespace std;
struct xx{
	int city;
	int road;
};
int arr[1000005];
xx xz[10006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v;
	int ans;
	for(int i=1;i<=m;i++){
		cin>>arr[i]>>u>>v;
		for(int j=1;j<=k;j++){
			cin>>xz[j].city>>xz[j].road;
			if(arr[i]=xz[j].road*n+xz[j].city){
				 ans=min(m,k*n);
			}
			if(arr[i]>xz[j].road*n+xz[j].city){
				if(m>k*n){
					ans=min(arr[i]*m,xz[j].road*n*k+xz[j].city*k)
				}else{
					ans=xz[j].road*n*k+xz[j].city*k;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
