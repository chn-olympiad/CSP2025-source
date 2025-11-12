#include<bits/stdc++.h>
#define ci const int
#define ri register int
using namespace std;
ci N=1e6+5;
int n,m,a1,a[200];
bool cmp(ci &a,ci &b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(ri i=1;i<=n*m;++i){
		scanf("%d",&a[i]);
	}
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ri i=1;i<=n*m;++i){
		if(a[i]==a1){
			int lm=(i-1)/n+1;
			int ln=(i-1)%n;
			if(lm&1) ln++;
			else ln=n-ln;
			printf("%d %d",lm,ln);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}