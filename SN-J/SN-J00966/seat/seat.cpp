//SN-J00966  袁浩文  西安辅轮中学
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1005],n,m;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int cnt=a[1];
	sort(a+1,a+n*m+1,[&](int x,int y){
		return x>y;
	});
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j]==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[i*n-j+1]==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}	
		}
	}
	return 0;
}
