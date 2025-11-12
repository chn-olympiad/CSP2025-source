#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][6];
int b[100005];
int c[100005];
int d[100005];
bool vis[100005];
int e,f,g;
int maxx[100005],cmaxx[100005],p;
long long ans=0;
bool cmp(int a,int b){
	return maxx[a]-cmaxx[a]>maxx[b]-cmaxx[b];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		e=0;f=0;g=0;
		ans=0;
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			maxx[i]=0;
			cmaxx[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		    for(int j=1;j<=3;j++){
			    if(a[i][j]>maxx[i]){
			    	maxx[i]=a[i][j];
			    	p=j;
				}
		    }
		    for(int j=1;j<=3;j++){
		    	if(a[i][j]!=maxx[i]){
		    		cmaxx[i]=max(cmaxx[i],a[i][j]);
				}
			}
			if(p==1)b[++e]=i;
			if(p==2)c[++f]=i;
			if(p==3)d[++g]=i;
	    }
	    sort(b+1,b+1+e,cmp);
	    for(int i=1;i<=min(n/2,e);i++){
	    	ans+=maxx[b[i]];
	    	vis[b[i]]=1;
		}
		sort(c+1,c+1+f,cmp);
	    for(int i=1;i<=min(n/2,f);i++){
	    	ans+=maxx[c[i]];
	    	vis[c[i]]=1;
		}
		sort(d+1,d+1+g,cmp);
	    for(int i=1;i<=min(n/2,g);i++){
	    	ans+=maxx[d[i]];
	    	vis[d[i]]=1;
		}
		for(int i=1;i<=n;i++){
			if(!vis[i])ans+=cmaxx[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
