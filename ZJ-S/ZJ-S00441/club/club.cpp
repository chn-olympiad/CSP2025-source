#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100100;
ll T,n,ans,x[3],nx[3];
ll chosen[3];
struct per{
	ll x[3],p0[3],op;
}a[N];
inline bool cmp(per& x,per& y){
	return x.op>y.op||(x.op==y.op&&(x.x[1]-x.x[0])>(y.x[1]-y.x[0]));
}
inline bool cmp2(ll& x,ll& y){
	return x>y;
}
inline void solve(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		memset(chosen,0,sizeof chosen);
		ans=0;
		cin>>n;
		for(int ii=1;ii<=n;ii++){//输入a结构体 
			for(int i=0;i<=2;i++) cin>>a[ii].x[i],nx[i]=a[ii].x[i];
			sort(a[ii].x,a[ii].x+3,cmp2);//排序 
			for(int i=0;i<=2;i++)
				for(int j=0;j<=2;j++)
					if(nx[j]==a[ii].x[i]) a[ii].p0[i]=j;
			a[ii].op=a[ii].x[0]-a[ii].x[1];//必写，第一个与第二个的差来排序 
		}sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){//选 
			if(chosen[a[i].p0[0]]<n/2){
				chosen[a[i].p0[0]]++;
				ans+=a[i].x[0];
			}//第一个 
			else if(chosen[a[i].p0[1]]<n/2){
				chosen[a[i].p0[1]]++;
				ans+=a[i].x[1];
			}//第二个 
			else{
				chosen[a[i].p0[2]]++;
				ans+=a[i].x[2];
			}//第三个 
		}cout<<ans<<endl;
	}
	return ;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	solve();
	return 0;
} 
