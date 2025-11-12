#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],q,d;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	q=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			d=i;
			break;
		}
	}
	int c=(d-1)/n+1,q=(d-1)%n+1;
	if(c%2==0){
		q=n-q+1;
	}
	cout<<c<<" "<<q;
	return 0;
}
