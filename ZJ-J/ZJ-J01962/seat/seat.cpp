#include<bits/stdc++.h>
using namespace std;
int n,m,r,cnt=1,x,y;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]) cnt++;
	}
	x=(cnt+n-1)/n;
	y=cnt%n;
	if(y==0) y=n;
	if(x%2==0) y=n+1-y;
	printf("%d %d\n",x,y);
	return 0;
}