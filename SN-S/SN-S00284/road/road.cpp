#include<bits/stdc++.h>
#define forf(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=1e6+5;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int v[N],u[N],w[N];
	forf(i,1,m) cin>>v[i]>>u[i]>>w[i];
	sort(w+1,w+m+1);
	long long ans=0;
	forf(i,1,m) ans+=w[i];
	cout<<ans;
	return 0;
}

