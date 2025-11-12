#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int x;
	cin >>x;
	int cnt=1; 
	for(int i=2;i<=n*m;i++){
		int a;
		cin >>a;
		if(a>x)cnt++;
	}
	int c=ceil(cnt*1.0/n);
	int r=(cnt-1)%n;
	if(c%2==1){
		cout <<c<<' '<<1+r;
	}if(c%2==0){
		cout <<c<<' '<<n-r;
	}
	return 0;
}

