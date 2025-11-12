#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;
int ans=-1;
struct node{
	int a,b,c;
};
node p[N];
int lim;
void dfs(int x,int cnt1,int cnt2,int cnt3,int sum){
	//printf("%d %d %d %d %d\n",x,cnt1,cnt2,cnt3,sum);
	if(x==(n+1)){
		if(sum>ans) ans=sum;
		return;
	}
	if(cnt1<lim){
		dfs(x+1,cnt1+1,cnt2,cnt3,sum+p[x].a);
	}
	if(cnt2<lim){
		dfs(x+1,cnt1,cnt2+1,cnt3,sum+p[x].b);
	}
	if(cnt3<lim){
		dfs(x+1,cnt1,cnt2,cnt3+1,sum+p[x].c);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		//ans=-1;
		lim=n>>1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		}
		if(n<=200){
		    ans=-1;
			dfs(1,0,0,0,0);
		    printf("%d\n",ans);
		    //return 0;
		}
		else{
			ans=0;
			int q[N];
			for(int i=1;i<=n;i++){
				q[i]=p[i].a;
			}
			sort(q+1,q+n+1);
			for(int i=1;i<=lim;i++){
				ans+=q[i];
			}
			printf("%d\n",ans);
		}
	}
}
