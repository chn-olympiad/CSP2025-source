#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+10;
int T,n;
struct node{
	long long x1,x2,d1,d2,s;
}d[N];
bool f[N];
bool cmp(node x,node y){
	return x.s>y.s;
}
void solve(){
	int cnt[4]={0,0,0,0};
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(x<=y&&x<=z){
			if(y>=z){
				d[i].x1=y;d[i].x2=z;d[i].d1=2;d[i].d2=3;
				d[i].s=y-z;
			}else {
				d[i].x1=z;d[i].x2=y;d[i].d1=3;d[i].d2=2;
				d[i].s=z-y;
			}
		}else if(y<=x&&y<=z){
			if(x>=z){
				d[i].x1=x;d[i].x2=z;d[i].d1=1;d[i].d2=3;
				d[i].s=x-z;
			}else {
				d[i].x1=z;d[i].x2=x;d[i].d1=3;d[i].d2=1;
				d[i].s=z-x;
			}
		}else {
			if(x>=y){
				d[i].x1=x;d[i].x2=y;d[i].d1=1;d[i].d2=2;
				d[i].s=x-y;
			}else {
				d[i].x1=y;d[i].x2=x;d[i].d1=2;d[i].d2=1;
				d[i].s=y-x;
			}
		}
	}
	sort(d+1,d+1+n,cmp);
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(cnt[d[i].d1]!=n/2){
			ans+=d[i].x1;
			cnt[d[i].d1]++;
		}else{
			ans+=d[i].x2;
			cnt[d[i].d2]++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
