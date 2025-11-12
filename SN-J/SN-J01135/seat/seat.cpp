#include<bits/stdc++.h>
using namespace std;
int n,m,l,h;
int a[105];
int ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	cin>>n>>m;
	int to=n*m;
	cin>>a[1];
	for(int i=2;i<=to;i++){
		cin>>a[i];
		if(a[i]>a[1])	ans++;
		
	}
	int l=ans/n+1;
	if(ans%n==0)	l--;
	if(l%2==0)	 h=l*n-ans+1;
	else	 h=ans-l*n+n;
	cout<<l<<" "<<h;
}
