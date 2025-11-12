#include<bits/stdc++.h>
using namespace std;
long long n,m;long long a[101],b[101],dx,dy,xx,yy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];b[a[i]]++;
	}
	dx=1;dy=0;yy=1;
	for(int i=100;i>=a[1];i--){
		if(b[i]){
			dy+=yy;
			if(dy>n){
				dy=n;
				yy=-1;
				dx++;
			}else if(dy<1){
				dx++;
				yy=1;
				dy=1;
			}
		}
	}
	cout<<dx<<' '<<dy;
	return 0;
}

