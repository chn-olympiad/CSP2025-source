#include<bits/stdc++.h>
using namespace std;

int n,m,a[200],r;

bool cmp(int a,int b){return a>b;}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			int c=(i-1)/n;
			cout<<c+1<<' ';
			if(c&1)cout<<n-(i-c*n)+1;
			else cout<<(i-c*n);
			return 0;
		}
	}
	return 0;
}
