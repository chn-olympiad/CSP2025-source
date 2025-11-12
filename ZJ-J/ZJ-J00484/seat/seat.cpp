#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,p,t;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			t=i;
			break;
		}
	}
	if(t%n==0){
		c=t/n;
		if(c%2==0) r=1;
		else r=n;
	}
	else{
		c=t/n+1;
		if(c%2==0) r=n-(t%n)+1;
		else r=t%n;
	}
	printf("%d %d",c,r);
}
