#include<bits/stdc++.h>
constexpr int N=1e5+2,ln=0x0d000721;
int n,m,a[102],r;
int main(){
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	std::cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		std::cin>>a[i];
	}
	r=a[1];
	std::sort(a+1,a+n*m+1,[&](int x,int y){
		return x>y;
	});
	int i=1,j=1,d=1,t=1;
	while(1){
		if(a[t]==r){
			std::cout<<j<<' '<<i;
			break;
		}
		t++;
		if(d==1){
			i++;
		}else{
			i--;
		}
		if(i==n+1){
			i=n,j++,d=0;
		}
		if(i==0){
			i=1,j++,d=1;
		}
	}
}
//uid:942578
