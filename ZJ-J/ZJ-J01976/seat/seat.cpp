#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int xx,int yy){
	return xx>yy;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int k=a[1],num;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			num=i;
			break;
		}
	}
	int y=num/n,x=num%n;
	if(x==0){
		if(y%2==0){
			x++;
		}else{
			x=n;
		}
	}else{
		y++;
		if(y%2==0)x=n-x+1;
	}
	cout<<y<<' '<<x;
	return 0;
}
