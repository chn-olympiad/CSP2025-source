#include<bits/stdc++.h>
using namespace std;
int n,m,g,x,y,a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a);
	g=1;
	for(int i=2;i<=n*m;i++){
		int t;
		scanf("%d",&t);
		if(t>a) g++;
	}
	x=(g+n-1)/n;
	y=g-n*(x-1);
	if(x%2==0){
		y=n+1-y;
	}
	printf("%d %d",x,y);
	return 0;
}
