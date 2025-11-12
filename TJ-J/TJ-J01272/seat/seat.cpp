#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int q=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==q){
			q=n*m-i;
			break;
		}
	}
	int x,y;
	y=ceil(q*1.0/n);
	if(y%2)x=q-(y-1)*n;
	else x=n+1-q%n;
	cout<<y<<" "<<x;
	return 0;
}
