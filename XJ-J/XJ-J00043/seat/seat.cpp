#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m,p,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
			cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			p = n*m-i+1;
		}
	}
	if(p%n==0)
		c = p/n;
	else c = p/n+1;
	if(c%2==1){
		if(p%n==0) r = n;
		else r=p%n;
	}
	else{
		if(p%n==0) r = 1;
		else p = n-p%n+1;
	}
	printf("%d %d",c,r);
	return 0;
}
