#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,l,r,k,op;
int a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])
			r++;
		else
			l++;
	}
	k=r/n+1;
	r-=(k-1)*n;
	op=k%2==0?n-r:r+1;
	cout<<k<<" "<<op;
	return 0;
}
