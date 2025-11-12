#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int check=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==check){
			int l=(i-1)/n+1;
			cout<<l<<' ';
			int len=(i-1)%n+1;
			if(l&1)cout<<len;
			else cout<<n-len+1;
			return 0;
		}
	}
	return 0;
}
