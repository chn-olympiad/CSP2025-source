#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+99;
int T,n,a[N][4];
int d1[N],d2[N],d3[N],d[N];
int get_max(int pos){
	if(a[pos][1]>a[pos][2]) return (a[pos][1]>a[pos][3] ? 1:3);
	return (a[pos][2]>a[pos][3] ? 2:3);
}
int get_nxt(int pos){
	int id=get_max(pos);
	if(id==1) return (a[pos][2]>a[pos][3] ? 2:3);
	if(id==2) return (a[pos][1]>a[pos][3] ? 1:3);
	if(id==3) return (a[pos][1]>a[pos][2] ? 1:2);
}
bool cmp(int x,int y){
	return a[x][get_max(x)]-a[x][get_nxt(x)]<
		a[y][get_max(y)]-a[y][get_nxt(y)];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=3;j++) cin>>a[i][j];
		for(int i=1;i<=n;i++){
			int id=get_max(i);
			ans+=a[i][id];
			if(id==1) d1[++cnt1]=i;if(id==2) d2[++cnt2]=i;if(id==3) d3[++cnt3]=i;
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2) cout<<ans<<endl;
		else{
			int cnt;
			if(cnt1>n/2){
				for(int i=1;i<=cnt1;i++) d[i]=d1[i];cnt=cnt1;
			}if(cnt2>n/2){
				for(int i=1;i<=cnt2;i++) d[i]=d2[i];cnt=cnt2;
			} if(cnt3>n/2){
				for(int i=1;i<=cnt3;i++) d[i]=d3[i];cnt=cnt3;
			}
			sort(d+1,d+cnt+1,cmp);
			for(int i=1;i<=(cnt-n/2);i++) ans-=(a[d[i]][get_max(d[i])]-a[d[i]][get_nxt(d[i])]);
			cout<<ans<<endl;
		}
	}
	return 0;
}
