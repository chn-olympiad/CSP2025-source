#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int p=0;
	for(int i=2;i<=n*m;i++)
		if(a[i]>a[1])p++;
	if((p/n+1)%2)printf("%d %d",p/n+1,p%n+1);
	else printf("%d %d",p/n+1,n-p%n);
	return 0;
}
