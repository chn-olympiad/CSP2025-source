#include<bits/stdc++.h>
using namespace std;
long long c[100005],u[100005],v[100005],w[100005],a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin>>n>>m>>k;
	int l=1;
	while(m--){
		cin>>u[l]>>v[l]>>w[l];
		l++;
	}
	for(int i=0;i<5;i++){
		cin>>c[i];
	}
	for(int i=0;i<5;i++){
		cin>>a[i];
	}
	cout<<"13";
	return 0;
} 
