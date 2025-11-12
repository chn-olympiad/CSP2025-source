#include <bits/stdc++.h>
using namespace std;
int n,m,a[410],b[20][20],jl_x,jl_y,now_x,now_y,cx;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	cx=a[1];
	sort(a+1,a+n*m+1);
	now_x=1,now_y=1;
	for(int i=n*m;i;--i){
		b[now_x][now_y]=a[i];
		if(a[i]==cx){
			jl_x=now_x,jl_y=now_y;
			break;
		}
		if(now_y&1){
			++now_x;
			if(now_x>n){
				now_x=n;
				++now_y;
			}
		}
		else{
			--now_x;
			if(now_x<1){
				now_x=1;
				++now_y;
			}
		}
	}
	cout<<jl_y<<' '<<jl_x;
	return 0;
}

