#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s=1,c,r;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a[1]);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1])s++;
	}
	sort(a+1,a+n*m+1,cmp);
	c=ceil(1.0*s/n);
	if(c%2==1)r=s-(c-1)*n;
	else r=n+1-(s-(c-1)*n);
	cout<<c<<" "<<r;
	return 0;
}
