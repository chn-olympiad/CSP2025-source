#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r;
struct node{
	long long cj,xr;
}a[105];
bool cmp(node x,node y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++) cin>>a[i].cj;
	a[1].xr=1;
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++)
		if(a[i].xr==1){
			if(i%n==0&&i/n%2!=0) c=i/n,r=n;
			if(i%n!=0&&(i/n+1)%2!=0) c=i/n+1,r=i%n;
			if(i%n==0&&i/n%2==0) c=i/n,r=1;
			if(i%n!=0&&(i/n+1)%2==0) c=i/n+1,r=i%n+1;
		}
	cout<<c<<" "<<r;
	return 0;
}
