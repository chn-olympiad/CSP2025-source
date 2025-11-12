#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ans[20][20];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++)ans[i][j]=a[++cnt];
		}
		else{
			for(int j=m;j>=1;j--)ans[i][j]=a[++cnt];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ans[i][j]==k){
				cout<<i<<" "<<j;
				return 0;
			}
	return 0;
}
