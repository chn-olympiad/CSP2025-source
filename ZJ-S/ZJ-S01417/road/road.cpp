#include<bits/stdc++.h>
using namespace std;
long long yxcs;
long long n,m,k,nt;
struct inm{
	long long ut,vt,ct;
}g[5000001],gt[5000001],tg[5000001];
long long cnt;
long long a[51][50001],ans=0;
bool us[51];
long long bcj[50001];
long long find(long long x){
	if(bcj[x]==x)return x;
	return bcj[x]=find(bcj[x]);
}
long long cmp(inm i,inm j){
	return i.ct<j.ct;
}
long long make(long long sum){
	for(long long i=1;i<=nt;i++)bcj[i]=i;
	for(long long i=1;i<=cnt;i++){
		gt[i]=g[i];
	}
	sort(gt+1,gt+1+cnt,cmp);
//	for(long long i=1;i<=cnt;i++){
//		printf("%lld %lld %lld\n",gt[i].ut,gt[i].vt,gt[i].ct);
//	}
	long long tc=1;
	for(long long i=1;i<=cnt;i++){
		gt[i].ut=find(gt[i].ut),gt[i].vt=find(gt[i].vt);
//		printf("%lld %lld\n",gt[i].ut,gt[i].vt);
		if(gt[i].ut!=gt[i].vt){
			sum+=gt[i].ct;
			bcj[gt[i].ut]=gt[i].vt;
			tc++;
			if(tc==nt)break;
		}
	}
	ans=min(ans,sum);
//	printf("%lld\n",sum);
	return 0;
}
long long dfs(long long id,long long sum){
//	yxcs++;
//	if(sum>ans)return 0;
	if(id>k){
		make(sum);
		return 0;
	}
	dfs(id+1,sum);
	nt++;
	for(long long i=1;i<=n;i++){
		g[++cnt]=(inm){nt,i,a[id][i]};
	}
	dfs(id+1,sum+a[id][0]);
	cnt-=n;
	nt--;
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		scanf("%lld %lld %lld",&tg[i].ut,&tg[i].vt,&tg[i].ct);
	}
	cnt=0,nt=n;
	for(long long i=1;i<=nt;i++)bcj[i]=i;
	long long tc=1;
	sort(tg+1,tg+1+m,cmp);
	for(long long i=1;i<=m;i++){
//		printf("%lld %lld\n",gt[i].ut,gt[i].vt);
		if(find(tg[i].ut)!=find(tg[i].vt)){
			ans+=tg[i].ct;
			bcj[find(tg[i].ut)]=find(tg[i].vt);
			g[++cnt]=tg[i];
			tc++;
			if(tc==nt)break;
		}     
	}
	for(long long i=1;i<=k;i++){
		for(long long j=0;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	dfs(1,0);
	printf("%lld\n",ans);
//	cout<<yxcs;
	return 0;
}