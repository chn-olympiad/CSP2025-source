#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=110;
int a[N],mp[N][N];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1],cnt=0,p=0;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(p==0){
			for(int j=1;j<=n;j++) mp[i][j]=a[n*m-cnt],++cnt;
			p=1;
		}
		else{
			for(int j=n;j>=1;j--) mp[i][j]=a[n*m-cnt],++cnt;
			p=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(p==0){
				for(int j=1;j<=n;j++){
					if(mp[i][j]==t){
						cout<<i<<' '<<j;
						return 0;
					}
				}
				p=1;
			}
			else{
				for(int j=n;j>=1;j--){
					if(mp[i][j]==t){
						cout<<i<<' '<<j;
						return 0;
					}
				}
				p=0;
			}
		}
	}
	return 0;
}
