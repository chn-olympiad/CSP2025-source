#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e2+10;
int a[N],sum;
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int R=a[1];
//	cout<<R<<endl;
	sort(a+1,a+1+n*m,cmp);
//	for(int i=1;i<=n*m;i++) cout<<a[i];
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){	
//			cout<<i<<endl;
			int k=ceil(i*1.0/n);
			cout<<k<<" ";
			int r=i-(k-1)*n;
			if(k%2) cout<<r;
			else cout<<n-r+1;
		}
	}
	return 0;
}