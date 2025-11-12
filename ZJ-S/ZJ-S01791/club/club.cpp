#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N],b[N],c[N],vis[N],d[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans=0,c1=0,c2=0,c3=0,K=0,m=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			int mx=max(a[i],max(b[i],c[i]));
			if(a[i]==mx){
				vis[i]=1,c1++;
			}
			else if(b[i]==mx){
				vis[i]=2,c2++;
			}
			else{
				vis[i]=3,c3++;
			}
			ans+=mx;
		}
		if(max(c1,max(c2,c3))<=n/2){
			printf("%d\n",ans);
			continue;
		}
		if(c1>n/2){
			K=1;
		}
		else if(c2>n/2){
			K=2;
		}
		else{
			K=3;
		}
		for(int i=1;i<=n;++i){
			if(K==1&&vis[i]==1){
				d[++m]=a[i]-max(b[i],c[i]);
			}
			if(K==2&&vis[i]==2){
				d[++m]=b[i]-max(a[i],c[i]);
			}
			if(K==3&&vis[i]==3){
				d[++m]=c[i]-max(a[i],b[i]);
			}
		}
		sort(d+1,d+1+m);
		for(int i=1;i<=max(c1,max(c2,c3))-n/2;++i){
			ans-=d[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}