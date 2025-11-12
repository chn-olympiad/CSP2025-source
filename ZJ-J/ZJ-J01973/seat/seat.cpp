#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e2+10;
int n,m,a[N],Rgot,poi;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	Rgot=a[1]; 
	sort(a+1,a+(n*m)+1,greater<int>());
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j]==Rgot){
				cout<<i<<' ';
				if(i&1) cout<<j<<endl;
				else cout<<n-j+1<<endl;
				return 0;
			}
		}
	}
	return 0;
}
