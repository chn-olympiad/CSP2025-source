#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],r;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			int x,y;
			if(i%n==0)x=i/n;
			else x=i/n+1;
			y=i%n;
			if(y==0)y=n;
			if(x%2==0)y=n-y+1;
			cout<<x<<" "<<y;
		}
	}
	return 0;
}
//csprp++;