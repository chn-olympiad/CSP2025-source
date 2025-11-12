#include<bits/stdc++.h>
using namespace std;
long long int n,m;
const int maxn=10000;
int a[maxn];
lzx(int n,int m){
	if(n==1&&m==1) return 0;
	cout<<m<<" "<<n;
	return lzx(n-1,m-1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==1&&m==1){
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
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}

	
	lzx(n,m);

}


