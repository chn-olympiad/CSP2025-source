#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int xx=1,yy=1,now=1;
	while(a[now]!=x){
		if(xx%2==1)yy++;
		else yy--;
		if(yy>n||yy<1){
			xx++;
			if(xx%2==0)yy=n;
			else yy=1;
		}
		now++;
	}printf("%d %d",xx,yy);
	return 0;
}

