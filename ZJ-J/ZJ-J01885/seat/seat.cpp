#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m,k,x,y;
int a[110];
bool cmp(int q,int p){
	return q>p;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	x=y=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			cout<<y<<' '<<x;
			break;
		}else{
			if(y&1){
				x++;
				if(x==n+1){
					x=n;
					y++;
				}
			}else{
				x--;
				if(x==0){
					x=1;
					y++;
				}
			}
		}
	}
	return 0;
}
