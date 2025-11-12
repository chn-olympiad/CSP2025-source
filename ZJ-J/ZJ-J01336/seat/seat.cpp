#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,num;
int c,r;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)	cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i;i--){
		if(a[i]==k){
			num=n*m+1-i;
			break;
		}
	}
	if(num%n==0){
		c=num/n;
		if(c%2==1)	r=n;
		else	r=1;
	}else{
		c=num/n+1;
		if(c%2==1)	r=num%n;
		else	r=n-(num%n)+1;
	}
	cout<<c<<' '<<r;
	
	return 0;
}