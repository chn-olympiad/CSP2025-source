#include<bits/stdc++.h>
using namespace std;
//struct w{
//	long long x,y,z,b;
//}a[1000005];
long long b[1000005],c[1000005],d[1000005],t,n,m,k,x,y,z,q,ma,ma1,ma2,ma3,num,b_1,c_1,d_1,f1,f2,f3,u,v,w;
string s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		x=0;
		for(int j=1;j<=n+1;j++){
			cin>>t;
			x+=t;
		}
		ma=max(ma,x);
	}
	cout<<ma;
	return 0;
}
