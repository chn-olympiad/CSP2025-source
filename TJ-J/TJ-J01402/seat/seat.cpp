#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,c,r,mi=1,n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a);
			if(a>mi){
				mi=a;
				c++;
				r++;
			}
		}
		printf("%d %d",c,r);
	}
	return 0;
}
