#include<bits/stdc++.h>
using namespace std;
const int N=11;
int n,m;
int a[N*N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;++i) cin>>a[i];
	int x=a[1],pos;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;++i){
		if(a[i]==x){
			pos=i;
			break;
		}
	}
	int c=(pos/n)+(pos%n!=0),r=(pos%n);
	if(r==0) r=n;
	if(c%2==0) r=(n-r+1);
	cout<<c<<' '<<r;
	return 0;
}
