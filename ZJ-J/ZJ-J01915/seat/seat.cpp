#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,dx[2]={-1,1};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1,x=1,y=1;i<=n*m;i++,x+=dx[y&1]){
		if(x<1||x>n)x-=dx[(y++)&1];
		if(a[i]==r)cout<<y<<' '<<x;
	}
	return 0;
}
