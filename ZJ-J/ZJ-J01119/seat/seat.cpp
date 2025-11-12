#include<stdio.h>
#include<algorithm>
#include<string.h>
#define CSP_IO freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
using namespace std;
int A[110];
signed main(){
	CSP_IO;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&A[i]);
	}
	int scr=A[1];
	sort(&A[1],&A[n*m+1]);
	int xb=n*m-(lower_bound(&A[1],&A[n*m+1],scr)-&A[0])+1;
	int les=xb-(xb-1)/n*n;
	int x=(xb-1)/n+1;
	if(x&1){
		printf("%d %d",x,les);
	}
	else printf("%d %d",x,n-les+1);
	return 0;
}
