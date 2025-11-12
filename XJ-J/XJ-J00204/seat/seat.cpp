#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],r,x,y;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==r){
			if (i%n==0) y=i/n;
			else y=i/n+1;
			if (y%2==0){
				x=n-(i-(y-1)*n)+1;
			}
			else{
				x=i-(y-1)*n;
			}
			break;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
