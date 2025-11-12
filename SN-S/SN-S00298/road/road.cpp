#include<bits/stdc++.h>
using namespace std;
int n,m,c[600],sum;
int s[60000];
int cd[600],ca[600],sl[600];
void dfs(int ni,int us,int fal){
	if(ni>n){
		if(us>=m){
			sum++;
//			for(int i=0;i<=ni;i++) printf("%d ",sl[i]);
//			printf("%d\n",fal+us);
			return;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(cd[i]!=1){
			cd[i]=1;
			ca[ni]=c[i];
			sl[ni]=i;
			if(fal>=ca[ni]||s[i]==0) dfs(ni+1,us,fal+1);
			else dfs(ni+1,us+1,fal);
			cd[i]=0;
//			ca[ni]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char a;
		scanf("%c ",&a);
		s[i]=a-'0';
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(1,0,0);
	printf("%d",sum);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

