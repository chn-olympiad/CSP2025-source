#include <bits/stdc++.h>
using namespace std;
struct S{
	int s,x;
}a[100];
bool cmp(S a1,S b1){
	return a1.s>b1.s;
}
signed main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].s);
		a[i].x=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j].x==1){
				if(i%2==0) printf("%d %d",i,n+1-j);
				else printf("%d %d",i,j);
			}
		}
	}
	return 0;
}

