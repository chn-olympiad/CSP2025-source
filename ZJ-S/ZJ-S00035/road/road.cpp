#include<bits/stdc++.h>
using namespace std;
long long n,m,k,t,s,x,y,z,a[1005][1005],b[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	memset(a,127,sizeof(a));
	for (int i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[x][y]=min(a[x][y],z);
	}for (int i=1;i<=1000;i++) for (int j=1;j<=1000;j++) b[++t]=a[i][j];
	sort(b+1,b+t+1);
	for (int i=t;i>=t-n;i--) s+=b[i];
	cout<<s;
}