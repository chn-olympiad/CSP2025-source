//niuziru SN-S00452 xiangaoxindiyizhongxue
#include<bits/stdc++.h>
using namespace std;
#define il inline
typedef long long ll;
il int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+13;
ll T,n,a[N][5],ans;
#define pii pair<int,int>
priority_queue<pii ,vector<pii> ,greater<pii > > h[5];
int num[5];
il void solve(){
	for(int i=1;i<=3;i++) while(!h[i].empty()) h[i].pop();
	num[1]=num[2]=num[3]=0;
	n=rd(),ans=0;
	for(int i=1;i<=n;i++){
		a[i][1]=rd(),a[i][2]=rd(),a[i][3]=rd();
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			h[1].push({a[i][1]-max(a[i][2],a[i][3]),i});
			ans+=a[i][1],num[1]++;
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			h[2].push({a[i][2]-max(a[i][1],a[i][3]),i});
			ans+=a[i][2],num[2]++;
		}
		else{
			h[3].push({a[i][3]-max(a[i][1],a[i][2]),i});
			ans+=a[i][3],num[3]++;
		}
	}
	int tp=0;
	for(int i=1;i<=3;i++){
		if(num[i]>n/2){
			tp=i;
			break;
		}
	}
	if(tp==0) printf("%lld\n",ans);
	else{
		pii u;
		while(num[tp]>n/2){
			u=h[tp].top();
			h[tp].pop();
			num[tp]--;
			ans-=u.first;
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=rd();
	while(T--){
		solve();
	}
	return 0;
}
