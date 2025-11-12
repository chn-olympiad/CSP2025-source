#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int T,n,a[100005][4],cnt[4]={0,0,0,0},ans;
pair<int,pair<int,pair<int,int> > > w[100005];
int g(int xxx,int yyy,int zzz){
	if(xxx>=yyy) swap(xxx,yyy);
	if(yyy>=zzz) swap(yyy,zzz);
	if(xxx>=yyy) swap(xxx,yyy);
	return zzz-yyy;
}
pair<int,int> p(int xxx,int yyy,int zzz){
	if(xxx>=yyy&&xxx>=zzz){
		if(yyy>=zzz) return {1,2};
		else return {1,3};
	}
	if(yyy>=xxx&&yyy>=zzz){
		if(xxx>=zzz) return {2,1};
		else return {2,3};
	}
	if(zzz>=xxx&&zzz>=yyy){
		if(xxx>=yyy) return {3,1};
		else return {3,2};
	}
}
bool cmp(pair<int,pair<int,pair<int,int> > > aaa,pair<int,pair<int,pair<int,int> > > bbb){
	return aaa.first>bbb.first;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		ans=0,cnt[1]=cnt[2]=cnt[3]=0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			w[i]={g(a[i][1],a[i][2],a[i][3]),{i,p(a[i][1],a[i][2],a[i][3])}};
		}
		sort(w+1,w+1+n,cmp);
		for(i=1;i<=n;i++){
			ans+=a[w[i].second.first][w[i].second.second.first];
			if(cnt[w[i].second.second.first]==n/2){
				cnt[w[i].second.second.second]++;
				ans-=w[i].first;
			}
			else{
				cnt[w[i].second.second.first]++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
