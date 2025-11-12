#include<bits/stdc++.h>
using namespace std;
#define f(i,x,y) for(int i=x;i<=y;i++)
int a[120];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	f(i,1,n*m) cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int now;
	f(i,1,n*m){
		if(a[i]==t){
			now=i;
			break;
		}
	}
	int lie=now/n+(now%n==0 ? 0:1);
	cout<<lie<<" ";
	if(lie%2!=0) {
		if(now%n!=0) cout<<now%n;
		else cout<<n;
	}
	else {
		if(now%n!=0) cout<<n-now%n+1;
		else cout<<1;
	}
	return 0;
}
