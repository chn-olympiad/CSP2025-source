#include <bits/stdc++.h>
using namespace std;
int n,m,k,l;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	a[0]=k;
	for(int i=1;i<m*n;i++){
		cin>>a[i];
	}
	sort(a,a+n*m);
	for(int i=0;i<m+n;i++){
		if(a[i]==k){
			l=m*n-i;
			break;
		}
	}
	if(l<=n){
		cout<<1<<' '<<l;
		return 0;
	}
	if(l%m) cout<<l/m+1<<' ';
	else cout<<l/m<<' ';
	if((l/m)%2==0) cout<<l%m;
	else cout<<n-l%m+1;
	return 0;
}
