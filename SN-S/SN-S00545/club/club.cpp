#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=1e5+10;
int n,T;
struct node{
	int v[4],id1,id2;
};
node a[maxn];
int dval1[maxn],dval2[maxn],dval3[maxn];
void solve(){
	// n/2 保证了不会出现同时满员 
	memset(a,0,sizeof(a));
	memset(dval1,0,sizeof(dval1));
	memset(dval2,0,sizeof(dval2));
	memset(dval3,0,sizeof(dval3));
	cin>>n;
	long long ans=0;
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].v[1]>>a[i].v[2]>>a[i].v[3];
		int ta=a[i].v[1],tb=a[i].v[2],tc=a[i].v[3];
		
		if(ta<tb) swap(ta,tb);
		if(tb<tc) swap(tb,tc);
		if(ta<tc) swap(ta,tc);
		if(ta<tb) swap(ta,tb);
		
		if(a[i].v[1]==ta) a[i].id1=1,dval1[++cnt1]=ta-tb;
		if(a[i].v[2]==ta) a[i].id1=2,dval2[++cnt2]=ta-tb;
		if(a[i].v[3]==ta) a[i].id1=3,dval3[++cnt3]=ta-tb;
		
		ans+=ta;
	}
	if(cnt1>n/2){
		sort(dval1+1,dval1+1+cnt1);
		for(int i=1;cnt1-i>=n/2;i++){
			ans-=dval1[i];
		}
	}
	else if(cnt2>n/2){
		sort(dval2+1,dval2+1+cnt2);
		for(int i=1;cnt2-i>=n/2;i++){
			ans-=dval2[i];
		}
	}
	else{
		sort(dval3+1,dval3+1+cnt3);
		for(int i=1;cnt3-i>=n/2;i++){
			ans-=dval3[i];
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
