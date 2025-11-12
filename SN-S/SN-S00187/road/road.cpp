#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		sum+=x;
	}
	for(int i=1;i<=k;i++){
		int x,y,z,t;
		cin>>t>>x>>y>>z;
		sum+=x;
	}
	cout<<sum;
	return 0;
}
