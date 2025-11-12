#include<bits/stdc++.h>
using namespace std;
int n,m,f;
int a[110],b[15][15];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==f){
			if(i%n==0)cout<<i/n<<" ";
			else cout<<i/n+1<<" ";
			if((i%n)%2!=0)cout<<i%m;
			else cout<<n-i%m;
		}
	return 0;
}
