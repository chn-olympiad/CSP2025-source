#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ans,half;
bool fb,fc;
struct node{
	int a,b,c;
}a[N];
bool cmp1(node a,node b){
	return a.a>b.a;
}
void dfs(int cnta=0,int cntb=0,int cntc=0,int now=-1,int ansnow=0){
	if(now==n){
		if(cnta<half){
			ans=max(ans,ansnow+a[now].a);
		}
		if(cntb<half){
			ans=max(ans,ansnow+a[now].b);
		}
		if(cntc<half){
			ans=max(ans,ansnow+a[now].c);
		}
	}
	if(cnta<=half){
		dfs(cnta+1,cntb,cntc,now+1,ansnow+a[now].a);
	}
	if(cntb<=half){
		dfs(cnta,cntb+1,cntc,now+1,ansnow+a[now].b);
	}
	if(cntc<=half){
		dfs(cnta,cntb,cntc+1,now+1,ansnow+a[now].c);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		half=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].b!=0){
				fb=true;
			}
			if(a[i].c!=0){
				fc=true;
			}
		}
		if(!fb&&!fc){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=half;i++){
				ans+=a[i].a;
			}
			printf("%d\n",ans);
		}else{
			dfs();
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}