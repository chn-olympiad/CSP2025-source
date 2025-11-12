#include<bits/stdc++.h>


using namespace std;
const int N=1e5+5;
int tt,n,a[N][4],dl[N];
inline bool cmp(int x,int y){return dl[x]>dl[y];}
inline void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",a[i]+1,a[i]+2,a[i]+3);
		int tmp[3]={a[i][1],a[i][2],a[i][3]};sort(tmp,tmp+3);
		dl[i]=tmp[2]-tmp[1];
	}
	int cnt[4]={0};
	vector<int>chosen[4];
	int ans=0;
	for(int i=1;i<=n;i++){
		int mp=max_element(a[i]+1,a[i]+4)-a[i];
		chosen[mp].push_back(i),cnt[mp]++,ans+=a[i][mp];
	}
	int max_chosen=max_element(cnt+1,cnt+4)-cnt;
	if(cnt[max_chosen]*2<=n){printf("%d\n",ans);return;}
	sort(chosen[max_chosen].begin(),chosen[max_chosen].end(),cmp);
	int req=cnt[max_chosen]-n/2;
	while(req--)ans-=dl[chosen[max_chosen].back()],chosen[max_chosen].pop_back();
	printf("%d\n",ans);
}
signed main()
{
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	scanf("%d",&tt);
	while(tt--)solve();
	return 0;
}
