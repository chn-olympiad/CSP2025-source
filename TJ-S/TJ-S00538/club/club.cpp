#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}d[100010];
bool cmp(node a,node b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
		}
		sort(d+1,d+n+1,cmp);
		long long cnt=0;
		for(int i=1;i<=n/2;i++){
			cnt+=d[i].a;
		}
		printf("%lld\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
