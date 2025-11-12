#include<bits/stdc++.h>
using namespace std;
long long a[105],n,m,s,mc,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
		if(a[i]==s)mc=n*m-i+1;
	mc%n==0?l=mc/n:l=mc/n+1;
	l%2==0?h=n-(mc-1)%n:h=(mc-1)%n+1;
	cout<<l<<" "<<h;
	return 0;
}