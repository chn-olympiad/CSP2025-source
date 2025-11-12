#include<bits/stdc++.h>
using namespace std;
int m,n,x,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=m*n;i;i--){
		if(a[i]==x){
			x=m*n+1-i;
			break;
		}
	}
	printf("%d %d",(x+n-1)/n,min((x+2*n-1)%(2*n)+1,2*n-((x+2*n-1)%(2*n))));
	fclose(stdin);
	fclose(stdout);
	return 0;
}