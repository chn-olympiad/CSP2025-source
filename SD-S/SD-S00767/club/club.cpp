#include<bits/stdc++.h>
#define int long long

const int N=114514;
 
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){s=(s<<3)+(s<<1)+(c-'0');c=getchar();}
	return s*f;
}
struct psn{
	int v[4],maxn[4];
};
psn a[N];
int ans;
int n;
std::vector<int> cnt[4];
void solve(){
	std::sort(a+1,a+1+n,[](psn x,psn y){
		if(x.v[x.maxn[1]]==y.v[y.maxn[1]]){
			if(x.v[x.maxn[2]]==y.v[y.maxn[2]])return x.v[x.maxn[3]]>y.v[y.maxn[3]];
			else return x.v[x.maxn[2]]>y.v[y.maxn[2]];	
		}
		return x.v[x.maxn[1]]>y.v[y.maxn[1]];
	});
	for(int i=1;i<=n;++i){
		cnt[a[i].maxn[1]].push_back(i);
		ans+=a[i].v[a[i].maxn[1]];
	}
	int pos=0;
	if(cnt[1].size()>n/2)pos=1;
	if(cnt[2].size()>n/2)pos=2;
	if(cnt[3].size()>n/2)pos=3;
//	printf("(%lld)\n",pos);
	if(pos==0){
		printf("%lld\n",ans);
		return;
	}
	std::vector<int> tmp(0);
	for(auto &i:cnt[pos]){
		tmp.push_back(a[i].v[a[i].maxn[2]]-a[i].v[a[i].maxn[1]]);
//		printf("(%lld)\n",a[i].v[a[i].maxn[2]]-a[i].v[a[i].maxn[1]]);
	}std::sort(tmp.begin(),tmp.end(),std::greater<int>());
	for(int i=0;i<cnt[pos].size()-(n/2);++i){
//		printf("##(%#lld)\n",tmp[i]);
		ans+=tmp[i];
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		cnt[1].clear();
		cnt[2].clear();
		cnt[3].clear();
		ans=0;
		for(int i=1;i<=n;++i){
			a[i].v[1]=read();
			a[i].v[2]=read();
			a[i].v[3]=read();
			int tmp[4]={0,a[i].v[1],a[i].v[2],a[i].v[3]};
			std::sort(tmp+1,tmp+4,std::greater<int>());
			bool vis[4]={0,0,0,0};
			for(int j=1;j<=3;++j){
				for(int k=1;k<=3;++k){
					if(!vis[k]&&tmp[j]==a[i].v[k]){a[i].maxn[j]=k;vis[k]=1;break;}
				}
			}
		}
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//无形的火 扭曲着世界轮廓
//高温线耗尽 夏日的盘中最后一滴颜色
//面对陌生的茧壳 和渺小的自我
//听到广阔 辰星银河 跑进我的耳朵 

//若痕迹都不曾亲眼见过
//若连平凡都显得像个传说
//还有什么时间惋惜惶惑
//我们约定在 光源处集合

//固执的 夏虫汲取着美梦解渴
//单薄的外壳 展开花纹 尽将内心诉说 
