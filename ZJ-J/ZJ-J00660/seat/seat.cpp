#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
int n,m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	int pos=lower_bound(a+1,a+n*m+1,x)-a;
	pos=n*m-pos+1;
	int y=(pos-1)%n+1;
	pos=(pos+n-1)/n;
	if(pos%2==0)y=(n-y+1);
	cout<<pos<<" "<<y<<endl;
	return 0;
}
