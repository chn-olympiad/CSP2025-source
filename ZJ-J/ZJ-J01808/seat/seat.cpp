#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N];
int n,m,c,r,s;

int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==t)s=i;
	c=(s-1)/n+1;
	if(c%2==1)r=(s-1)%n+1;
	else r=n-((s-1)%n+1)+1;
	cout<<c<<" "<<r;
	return 0;
}