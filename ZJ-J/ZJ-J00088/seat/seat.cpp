#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[105],b[11][11],x,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",a+i);
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i;
	for(i=1;a[i]!=x;)i++;
	i--;
	h=i/n+1;
	if(h%2==1)l=i%n+1;
	else l=n-i%n;
	printf("%d %d",h,l);
	return 0;
}
