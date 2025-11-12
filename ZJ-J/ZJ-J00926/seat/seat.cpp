#include<bits/stdc++.h>
using namespace std;
int a[10005],n,m,t,x,y,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==t){
			num=n*m-i+1;
			if(num%n==0)y=num/n;
			else y=num/n+1;
			if(y%2==1)x=num-n*(y-1);
			else x=y*n-num+1;
			cout<<y<<" "<<x;
			break;
		}
	}
	return 0;
}
