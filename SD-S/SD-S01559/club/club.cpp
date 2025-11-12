#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
struct Stut{
	ll mydd;
	ll stidx;
	friend bool operator <(const Stut a,const Stut b){
		return a.mydd>b.mydd;
	} 
}tmp[N],ttmp[N];
ll myd[N][4],Tstcs,n,dfsres;
bool flg2,flg3;
void dfs(ll curr,ll cnt1,ll cnt2,ll cnt3,ll sum){
	if(curr==n+1){
		if(cnt1<=(n/2)&&cnt2<=(n/2)&&cnt3<=(n/2)){
			dfsres=max(dfsres,sum);
			return;
		}
	}
	for(int i=1;i<=3;i++){
		if(i==1&&cnt1+1<=n/2) dfs(curr+1,cnt1+1,cnt2,cnt3,sum+myd[curr][1]);
		if(i==2&&cnt2+1<=n/2) dfs(curr+1,cnt1,cnt2+1,cnt3,sum+myd[curr][2]);
		if(i==3&&cnt3+1<=n/2) dfs(curr+1,cnt1,cnt2,cnt3+1,sum+myd[curr][3]);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>Tstcs;
	for(int _Tstc=1;_Tstc<=Tstcs;_Tstc++){
		cin>>n;
		flg3=flg2=1;
		for(int i=1;i<=n;i++){
			cin>>myd[i][1]>>myd[i][2]>>myd[i][3];
			if(myd[i][2]!=0) flg2=0;
			if(myd[i][3]!=0) flg3=0;
		}
		if(flg2&&flg3){
			for(int i=1;i<=n;i++) tmp[i].mydd=myd[i][1];
			sort(tmp+1,tmp+n+1);
			ll ans=0;
			for(int i=1;i<=n/2;i++) ans+=tmp[i].mydd;
			cout<<ans<<endl;
			continue;
		}else if(n<=20){
			dfsres=-1;
			dfs(1,0,0,0,0);
			cout<<dfsres<<endl;
			continue;
		}
	}
	return 0;
}

