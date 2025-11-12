#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int t,n;
int d[MAXN];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(d,0,sizeof(d));
		int a;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&a,&a);
		}
		sort(d+1,d+1+n);
		int res=0;
		for(int i=n/2+1;i<=n;i++){
			res+=d[i];
		}
		printf("%d\n",res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

