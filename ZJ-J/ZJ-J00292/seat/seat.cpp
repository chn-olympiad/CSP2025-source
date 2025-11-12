#include<bits/stdc++.h>
using namespace std;
#define int long long
 int n,m,x;
 int a[110];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int j=1,lg=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++){
				if(a[lg]==x){
					cout<<j<<" "<<i;
					return 0;
				}
				lg++;
			}
		}else{
			for(int i=n;i>=1;i--){
				if(a[lg]==x){
					cout<<j<<" "<<i;
					return 0;
				}
				lg++;
			}
		}
	}
	return 0;
}
