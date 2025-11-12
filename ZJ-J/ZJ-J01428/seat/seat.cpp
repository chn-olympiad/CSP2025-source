#include<bits/stdc++.h>
using namespace std;
int n,m,R,R_id,R_x,R_y;
int a[105];
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==R)R_id=i;
	R_x=(R_id%m?R_id/m+1:R_id/m);
	R_y=(R_x%2?(R_id%m?R_id%m:m):(R_id%m?m-R_id%m+1:1));
	cout<<R_x<<' '<<R_y<<endl;
	return 0;
}

