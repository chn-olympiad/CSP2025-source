#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,j=0,t=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int u=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)if(a[i]==u)j=1+n*m-i;
	while(j>n){
		j=j-n;
		t++;
	}
	if(t%2==1)cout<<t<<" "<<j;
	else cout<<t<<" "<<n-j+1;
	return 0;
}
