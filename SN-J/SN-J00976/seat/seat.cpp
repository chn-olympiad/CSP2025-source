//许明宇-SN-J00976-西安市高新第一学校
#include <bits/stdc++.h>
using namespace std;
int n,m,a[200],r,c,num;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			r=ceil(1.0*i/n);
			if(r%2==0){
				c=n-i%n+1;
				if(i%n==0){
					c=1;
				}
			}else{
				c=i%n;
				if(i%n==0){
					c=n;
				}
			}
			break;
		}
	}
	cout<<r<<' '<<c;
	return 0;
}
