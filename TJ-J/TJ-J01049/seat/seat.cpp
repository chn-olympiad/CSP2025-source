#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,f,o,p;
	cin>>n>>m;
	int a[n*m+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	int g=1;
	for(int i=m*n;i>=1;i--){
		if(a[i]==r){
			break;
		}
	    g++;
	}
	o=g/n;
	if(g%n!=0){
		o++;
	}
	if(o%2==1 && g%n==0){
		p=n;
	}
	else if(g%n==0){
		p=1;
	}
	else if(o%2==1){
		p=g%n;
	}
	else if(o%2==0)
	{
		p=n-g%n;
	}
	cout<<o<<" "<<p;
	return 0;
}
