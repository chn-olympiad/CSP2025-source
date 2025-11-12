#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int p=0;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>=a[1])p++;
	}
	int x=1,y=1;
	for(int i=2;i<=p;i++){
		x=x+((y&1)?1:-1);
		if(x>n)x=n,y++;
		if(x<1)x=1,y++;
	}
	printf("%d %d\n",y,x);
	return 0;
}