//我常常追忆过去。
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,a[MAXN][5],_1[MAXN],_2[MAXN],_3[MAXN],cnt1,cnt2,cnt3,ans;
bool cmp1(int x,int y){
	int minn1=min(a[x][1]-a[x][2],a[x][1]-a[x][3]),minn2=min(a[y][1]-a[y][2],a[y][1]-a[y][3]);
	return minn1<minn2;
}
bool cmp2(int x,int y){
	int minn1=min(a[x][2]-a[x][1],a[x][2]-a[x][3]),minn2=min(a[y][2]-a[y][1],a[y][2]-a[y][3]);
	return minn1<minn2;
}
bool cmp3(int x,int y){
	int minn1=min(a[x][3]-a[x][1],a[x][3]-a[x][2]),minn2=min(a[y][3]-a[y][1],a[y][3]-a[y][2]);
	return minn1<minn2;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxn=max(a[i][1],max(a[i][2],a[i][3]));
		if(a[i][1]==maxn) _1[++cnt1]=i;
		else if(a[i][2]==maxn) _2[++cnt2]=i;
		else _3[++cnt3]=i;
		ans+=maxn;
	} if(cnt1>n/2){
		sort(_1+1,_1+cnt1+1,cmp1);
		for(int i=1;i+n/2<=cnt1;i++) ans-=min(a[_1[i]][1]-a[_1[i]][2],a[_1[i]][1]-a[_1[i]][3]);
	} else if(cnt2>n/2){
		sort(_2+1,_2+cnt2+1,cmp2);
		for(int i=1;i+n/2<=cnt2;i++) ans-=min(a[_2[i]][2]-a[_2[i]][1],a[_2[i]][2]-a[_2[i]][3]);
	} else if(cnt3>n/2){
		sort(_3+1,_3+cnt3+1,cmp3);
		for(int i=1;i+n/2<=cnt3;i++) ans-=min(a[_3[i]][3]-a[_3[i]][1],a[_3[i]][3]-a[_3[i]][2]);
	} cout<<ans<<"\n";
	cnt1=cnt2=cnt3=ans=0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
}
