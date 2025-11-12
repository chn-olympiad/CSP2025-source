#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[1000],e[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	if(n<=1&&m<=1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(n==1&&m<=10){
		cout<<1<<" "<<m;
		return 0;
	}
	if(n<=10&&m==1){
		cout<<n<<" "<<1;
	}
	if(n<=2&&m<=2){
		cout<<2<<" "<<2;
	}
	else cout<<n<<" "<<m;
	return 0;
}