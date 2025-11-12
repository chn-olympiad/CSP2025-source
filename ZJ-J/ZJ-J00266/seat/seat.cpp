#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j]==r){
				if(i&1) cout<<i<<" "<<j;
				else cout<<i<<" "<<n-j+1;
				return 0;
			}
		}
	}
}
