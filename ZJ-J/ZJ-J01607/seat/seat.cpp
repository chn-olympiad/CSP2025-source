#include<bits/stdc++.h>
using namespace std;
int n,m,x;
struct zdy{
	int x,id;
	bool operator<(const zdy &B)const{return x>B.x;}
}a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			x=i;
			break;
		}
	}
	int y=x%(2*n);
	if(y==0) y=2*n;
	if(y<=n){
		int c=y,r=x/n+1;
		if(x%n==0) r--;
		printf("%d %d\n",r,c);
	}else{
		y-=n;
		int c=n-y+1,r=x/n+1;
		if(x%n==0) r--;
		printf("%d %d\n",r,c);
	}
	return 0;
}
