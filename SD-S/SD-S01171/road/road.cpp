#include<bits/stdc++.h>
using namespace std;
struct road{
	long long x,y,w,l;
	bool operator<(const road &A)const{
		return w<A.w;
	}
}a[5000009],b[5000009],ab[5000009];
long long n,m,k,tnc=0;
long long c[109],v[109][50009],fa[50009],nd[109],fa2[50009],fa3[50009],fans=0,ans=0;
long long find(long long x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
long long find2(long long x){
	if(fa2[x]==x){
		return x;
	}
	fa2[x]=find2(fa2[x]);
	return fa2[x];
}
void dfs(long long x){
	
	if(x>k){
//		if(sum>=fans)
//			return ;
		memset(b,0,sizeof(b));
		long long sna=0,num=0,ccnt=1;
		for(long long i=1;i<=k;i++){
			if(nd[i]==1){
				sna+=c[i];
//				printf("%lld ",i);
				for(long long j=1;j<=n;j++){
					num++;
					b[num].x=j,b[num].y=n+i,b[num].w=v[i][j];
				}
			}
		}
		sort(b+1,b+num+1);
//		printf("\n");
//		printf("%lld\n",num);
		long long la=1,lb=1,m2=0;
//		printf("sort:\n");
		while(1){
//			printf(" %lld %lld %lld %lld\n",la,lb,a[la].w,b[lb].w);
			if(la>m){
				while(lb<=num){
					ab[++m2]=b[lb];
					lb++;
				}
				break;
			}
			else if(lb>num){
				while(la<=m){
					ab[++m2]=a[la];
					la++;
				}
				break;
			}
			else{
				if(a[la].w<b[lb].w){
					ab[++m2]=a[la];
					la++;
				}
				else{
					ab[++m2]=b[lb];
					lb++;
				}
			}
		}
//		printf("m2:\n");
		for(long long i=1;i<=m2&&ccnt<=n+k;i++){
//			printf(" %lld %lld %lld\n",ab[i].x,ab[i].y,ab[i].w);
			long long x=find2(ab[i].x),y=find2(ab[i].y);
//			printf("  %lld %lld\n",x,y);
			if(x!=y){
				ccnt++;
				fa2[x]=y;
				sna+=ab[i].w;
			}
		}
		memset(b,0,sizeof(b));
		memset(ab,0,sizeof(ab));
		for(long long i=1;i<=n+k+3;i++){
			fa2[i]=i;
		}
		m2=0;
//		printf("%lld %lld %lld\n",sum,sna,sum+sna);
		fans=min(fans,sna);
		return ;
	}
	dfs(x+1);
	nd[x]=1;
	dfs(x+1);
	nd[x]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=n+k+2;i++){
		fa[i]=i;
		fa2[i]=i;
		fa3[i]=i;
	}
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].w);
	}
	sort(a+1,a+m+1);
	for(long long i=1;i<=m;i++){
		b[i]=a[i];
		long long x=find(a[i].x),y=find(a[i].y);
		if(x!=y){
			fa[x]=y;
			a[i].l=1;
			ans+=a[i].w;
		}
	}
	if(k==0){
		printf("%lld\n",ans);
		return 0;
	}
	long long maxx=0;
	for(long long i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		maxx=max(maxx,c[i]);
		for(long long j=1;j<=n;j++){
			scanf("%lld",&v[i][j]);
			maxx=max(maxx,v[i][j]);
		}
//		sort(v[i]+1,v[i]+n+1);
	}
//	for(long long i=1;i<=k;i++){
//		printf("%lld\n",c[i]);
//	}
	if(maxx==0){
		printf("0\n");
		return 0;
	}
	fans=ans;
	dfs(1);
	printf("%lld\n",fans);
	return 0;
} 
