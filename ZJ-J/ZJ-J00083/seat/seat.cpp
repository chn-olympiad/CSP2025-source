#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ans,x,y;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i)
	if(a[i]==ans){
		x=i/(n*2);y=i%(n*2);
		if(y==0){
			y=2*n;
			--x;
		}
		if(y>n)cout<<x*2+2<<" "<<2*n+1-y<<"\n";
		else cout<<x*2+1<<" "<<y<<"\n";
	}
	return 0;
}
