#include<bits/stdc++.h>
using namespace std;
const  int N=1e5+10;
int t,n,m;
struct node{
	int a,b,c;
}d[N];
int dp[N][3],a[N][3],s[N][3];
bool cmp(node x,node y){
	return x.a>y.a;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(dp , 0 , sizeof dp );
		scanf("%d",&n);
		m=n/2;
		int flag=1;
		for(int i=1,x,y,z;i<=n;i++){
			
			scanf("%d%d%d",&x,&y,&z);
			if(y>0||z>0) flag=0;
			d[i].a=x;
			d[i].b=y;
			d[i].c=z;
		}if(flag){
			sort(d+1,d+1+n,cmp);
		}
		int ans=0;
		for(int i=1;i<=n/2;i++) ans+=d[i].a;
		
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
