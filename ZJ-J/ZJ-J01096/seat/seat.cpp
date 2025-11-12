#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;

int n,m,t;
int a[200];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>t;
	a[1]=t;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	int tx=1,ty=1,d=1;
	for(int i=n*m;i>=1;i--){
//		cout<<a[i]<<" ";
		if(a[i]==t){
			printf("%d %d",ty,tx);
			return 0;
		}
		tx+=d;
		if(tx>n||tx<1){
			ty++,tx-=d;
			d*=-1;
		}

	}

	return 0;
}

