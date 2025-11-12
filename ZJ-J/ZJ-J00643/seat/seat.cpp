#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,x,l,a[1000];
bool cmp(int q,int h){
	return q>h;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++) 
		if(a[i]==x){
			x=i;break;
		}
	if(x%n==0){
		if((x/n)%2==0){
			cout<<x/n<<" "<<1;return 0;
		}
		else{
			cout<<x/n<<" "<<n;return 0;
		}
	}
	l=x/n;
	if((l+1)%2==0){
		cout<<l+1<<" "<<n-(x-l*n)+1;return 0;
	}
	else{
		cout<<l+1<<" "<<x-l*n;return 0;
	}
	return 0;
}
