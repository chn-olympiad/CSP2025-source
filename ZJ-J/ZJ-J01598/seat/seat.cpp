#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200],R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,greater<long long>());
	for(int i=1;i<=m;i++)
		if(i&1)
			for(int j=1;j<=n;j++)
				if(a[(i-1)*n+j]==R){
					cout<<i<<' '<<j;
					return 0;
				}
				else continue;
		else
			for(int j=n;j>=1;j--)
				if(a[(i-1)*n+n-j+1]==R){
					cout<<i<<' '<<j;
					return 0;
				}
			else continue;
}