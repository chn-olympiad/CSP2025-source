#include <bits/stdc++.h>
using namespace std;
int n,m,l,x,y;
int a[105];
int s[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			l=i;
			break;
		}
	}
	if(l%n==0){
		x=l/n;
		if(x%2==0) y=1;
		else y=n;
	}
	else if(l%n==1){
		x=l/n+1;
		if(x%2==0)y=n;
		else y=1;
	}
	else{
		x=l/n+1;
		if(x%2==0) y=n-l%n+1;
		else y=l%n;
	}
	cout<<x<<" "<<y;
	return 0;
}
