//王梓乔 SN-S00500 西安高新第一初级中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline bool cmp(int a,int b){return a>b;}
int n,m;
struct pig{
	int x,y,z;
}a[100005];
int dp[2][300005];
vector<pair<int,int>> chi;
int ans;
int ansx[100005],cnt;
inline void reans(int x){
	cnt=0;
	pair<int,int> p;
	int ax[5];
	for(int i=0,maxn,minn;i<n;i++)
		if(chi[i].first==x){
			p=chi[i];
			if(x==1)	ansx[++cnt]=a[p.second].x;
			else	if(x==2)	ansx[++cnt]=a[p.second].y;
			else		ansx[++cnt]=a[p.second].z;
			ax[1]=a[p.second].x,ax[2]=a[p.second].y,ax[3]=a[p.second].z;
			sort(ax+1,ax+3+1);
			ansx[cnt]-=ax[2];
		}
	sort(ansx+1,ansx+cnt+1,cmp);
	for(int i=n/2+1;i<=cnt;i++)	ans-=ansx[i];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		chi.clear(),ans=0;
		n=read();
		for(int i=1;i<=n;i++)	a[i].x=read(),a[i].y=read(),a[i].z=read();
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1,maxn;i<=n;i++){
			maxn=max(a[i].x,max(a[i].y,a[i].z));
			if(maxn==a[i].x)	cnt1++,chi.emplace_back(1,i);
			else	if(maxn==a[i].y)	cnt2++,chi.emplace_back(2,i);
			else	if(maxn==a[i].z)	cnt3++,chi.emplace_back(3,i);
			ans+=maxn;
		}
		if(cnt1>n/2||cnt2>n/2||cnt3>=n/2){
			if(cnt1>n/2)	reans(1);
			else	if(cnt2>n/2)	reans(2);
			else	reans(3);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
