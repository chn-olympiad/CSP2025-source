//luogu Lament_Rain 1157620 
//freopen
//.ans
//如果我能去NOIp的话我会带着我的拉面雨的（ 
/*
T1
这是可以贪的吗
猜一手 
15:48 切A ?
except 100 pts
*/ 
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Compassion{
	const int N=1.1e5+8;
	int n,cnt[4];
	struct p{
		int val1,val2,val3,dis,id,maxv,secv;
	}a[N];
	bool vis[N],ful[4],resorted;
	bool cmp(p p1,p p2){
		return p1.dis==p2.dis?p1.maxv>p2.maxv:p1.dis>p2.dis;
	}
	void solve(){
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		memset(ful,0,sizeof(ful));
		resorted=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int v1,v2,v3;
			cin>>v1>>v2>>v3;
			int tmp[3]={v1,v2,v3};
			sort(tmp,tmp+3);
			int maxv=tmp[2],secv=tmp[1];
			a[i]={v1,v2,v3,maxv-secv,i,maxv,secv};
		}
		sort(a+1,a+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
//			cout<<i<<'\n';
			if(vis[a[i].id])continue;
			vis[a[i].id]=1;
//			cout<<a[i].id<<' '<<a[i].val1<<' '<<a[i].val2<<' '<<a[i].val3<<'\n';
			if(resorted){
				ans+=a[i].maxv;
			}
			else {
				int maxval=a[i].maxv,maxid;
				if(maxval==a[i].val1)maxid=1;
				else if(maxval==a[i].val2)maxid=2;
				else maxid=3;
				cnt[maxid]++;
				ans+=maxval;
				if(cnt[maxid]>=(n>>1)&&(!resorted)){
//					cout<<"s\n";
					ful[maxid]=1;
					for(int j=1;j<=n;j++){
						if(ful[1]){
							a[j].val1=0;
							a[j].maxv=max(a[j].val2,a[j].val3),a[j].secv=min(a[j].val2,a[j].val3);
							a[j].dis=a[j].maxv-a[j].secv;
						}
						else if(ful[2]){
							a[j].val2=0;
							a[j].maxv=max(a[j].val1,a[j].val3),a[j].secv=min(a[j].val1,a[j].val3);
							a[j].dis=a[j].maxv-a[j].secv;
						}
						else {
							a[j].val3=0;
							a[j].maxv=max(a[j].val1,a[j].val2),a[j].secv=min(a[j].val1,a[j].val2);
							a[j].dis=a[j].maxv-a[j].secv;
						}
					}
					sort(a+1,a+1+n,cmp);
					resorted=1;
					i=0;
				}
			}
		}
		cout<<ans<<'\n';
	}
	void Foloron(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(0);
		int t;
		cin>>t;
		while(t--)solve();
	}
}
signed main(){
	Compassion::Foloron();
	return 0;
}
//摩耶，一。 
//如果哪天有人发现了这本日志，它存在的意义便是你。 

