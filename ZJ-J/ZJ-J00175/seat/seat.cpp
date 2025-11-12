#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++)
		if(a[i]==s){
			int x=(i%n?i/n+1:i/n),y=0;
			if(i<n)y=i;
			else y=(x&1?n-x*n+i:n+i-x*n+1);
			cout<<x<<" "<<y;
			break;
	    }
	return 0;
}