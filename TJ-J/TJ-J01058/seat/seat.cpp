#include<bits/stdc++.h>
using namespace std;
const int N = 110;

int n,m,grd,r,c;
int a[N];
int vis[N];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		vis[a[i]]=1;
	}
	for(int i=100;i>=a[1];i--){
		if(vis[i]) ++grd;
	}
	r=(grd+n-1)/n;
	c=(r&1?(grd%n?grd%n:n):n-(grd%n?grd%n:n)+1);
	cout<<r<<' '<<c;
	return 0;
}
