#include<bits/stdc++.h>
using namespace std;
int t,n,maxn,clb,lim,ans,totans;
int a[101438][5];
struct node{
	int love;
	int person;
	int club;
}c[301502];
bool vis[101504];
int cap[5];
bool cmp(node u,node v){
	return u.love>v.love;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(vis,0,sizeof(vis));
		memset(cap,0,sizeof(cap));
		ans=0;
		totans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=3;ii++){
				scanf("%d",&a[i][ii]);
				c[(i-1)*3+ii].love=a[i][ii];
				c[(i-1)*3+ii].person=i;
				c[(i-1)*3+ii].club=ii;
			}
		}
		sort(c+1,c+3*n+1,cmp);
		for(int st=1;st<=(3*n);st++){
			ans=0;
			memset(vis,0,sizeof(vis));
			memset(cap,0,sizeof(cap));
			for(int i=st;i<=(3*n);i++){
				if(vis[c[i].person])continue;
				if(cap[c[i].club]>=(n/2))continue;
				ans+=c[i].love;
				vis[c[i].person]=1;
				cap[c[i].club]++;
			}
			totans=max(totans,ans);
		}
		printf("%d\n",totans);
	}
	return 0;
}
/*





























*/
