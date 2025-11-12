#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",a+i);
		if(a[i]>a[1]) cnt++;
	}
	int x=1,y=1,d=1;
	while(cnt--){
		x+=d;
		if(x>n) x=n,y++,d=-1;
		if(x<1) x=1,y++,d=1;
	}printf("%d %d",y,x);
	return 0;
}

