#include<bits/stdc++.h>
using namespace std;
const int N=1000004;
int n,m,k,u[N],v[N],w[N],c,a[N],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	cin>>c;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	cout<<ans;
	}
	else{
		for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i]; 
	cin>>c;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		ans+=a[i];
	}
	cout<<ans;	
	} 
	return 0;
}
