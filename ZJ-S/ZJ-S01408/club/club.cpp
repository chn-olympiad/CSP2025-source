#include <bits/stdc++.h>
using namespace std;
#define M 100005
int T;
int n;
int cnt[4],vis[M];
long long ans;
struct pt{
	int id,num;
};
struct st{
	int fi,se;
};
vector<pt> p[M];
st ch[M];
bool cmp(pt x,pt y){
	return x.num>y.num;
}
bool cmp2(st x,st y){
	return x.fi-x.se<y.fi-y.se;
}
int main(void){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		memset(ch,0,sizeof(ch));
		for(int i=1;i<=n;i++)p[i].clear();
		int ct=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x;
				cin>>x;
				p[i].push_back(pt{j,x});
			}
			sort(p[i].begin(),p[i].end(),cmp);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			ans+=p[i][0].num;
			cnt[p[i][0].id]++;
		}
		int li=-1;
		if(cnt[1]>n/2)li=1;
		else if(cnt[2]>n/2)li=2;
		else if(cnt[3]>n/2)li=3;
		if(li!=-1){
			for(int i=1;i<=n;i++){
				if(p[i][0].id==li){
					ct++;
					ch[ct].fi=p[i][0].num;
					ch[ct].se=p[i][1].num;
				}
			}
			sort(ch+1,ch+1+ct,cmp2);
			for(int i=1;i<=cnt[li]-n/2;i++){
				ans-=ch[i].fi-ch[i].se;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
