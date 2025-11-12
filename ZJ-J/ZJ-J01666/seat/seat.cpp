#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],s=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a[1]);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1])s++;
	}
	if(s%n==0)y=n;
	else y=s%n;
	if(y==n)x=s/n;
	else x=s/n+1;
	cout<<x<<" "<<y;
	return 0;
}
