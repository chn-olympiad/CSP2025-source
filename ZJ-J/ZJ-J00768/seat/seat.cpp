#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b;
bool cmp(int x,int y){
	return x>y; 
}
main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	b=a[0],sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)if(a[i]==b)cout<<(i/n+1)<<' '<<((i/n+1)%2?(i%n+1):(n-i%n)),exit(0);
}
