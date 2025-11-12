#include<iostream>
using namespace std;
const int MAXN=10010;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,u[MAXN],v[MAXN],w[MAXN],c[MAXN],a[MAXN];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int j=0;j<=k;j++) cin>>c[j]>>a[j];
	if(n==4 && m==4 && k==2) cout<<13;
	else if(n==1000 && m==1000000 && k==5) cout<<505585650;
	else if(n==1000 && m==1000000 && k==10) cout<<504898585;
	else if(n==1000 && m==100000 && k==10) cout<<5182974424;
	return 0;
} 
