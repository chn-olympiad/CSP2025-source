#include<bits/stdc++.h>
using namespace std;
int n,m,mp[15][15];
struct xu{
	int v,x,y,id;
}a[105];
bool cmp(xu a,xu b){
	return a.v>b.v;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].v,a[i].id=i;
	
	sort(a+1,a+n*m+1,cmp);
	
	int k=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				mp[i][j]=a[++k].v;
				a[k].x=i,a[k].y=j;
			}
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				mp[i][j]=a[++k].v;
				a[k].x=i,a[k].y=j;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<a[i].x<<' '<<a[i].y<<'\n';
			return 0;
		}
	}
	return 0;
}