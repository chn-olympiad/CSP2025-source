#include<bits/stdc++.h>
using namespace std;
int bao,t,i,n,m,a[110],y;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>a[i];
	bao=a[1];
	sort(a+1,a+1+m*n,cmp);
	for(i=1;i<=n*m;i++)
		if(a[i]==bao){
			t=i;break;
		}
	if(t%n==0){
		y=t/n;
		if(y%2==1){
			cout<<y<<" "<<n;
			return 0;
		}
		else{
			cout<<y<<" "<<1;
			return 0;
		}
	}
	else{
		y=t/n+1;
		if(y%2==0){
			cout<<y<<" "<<n*y-t+1;
			return 0;
		}
		else{
			cout<<y<<" "<<t-(y-1)*n;
			return 0;
		}
	}
}
