#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=110000;
ll n,T,cnt[5];
struct sat{
	ll x,y,z;
}a[maxn],fclub[maxn],sclub[maxn],tclub[maxn];
ll fl,sl,tl;
bool cmp1(sat p,sat q){//genjuyuhoulianggeclubdechazhicongxiaodaodapaixu(xiatong)
	ll fmin=min(abs(p.x-p.y),abs(p.x-p.z));
	ll smin=min(abs(q.x-q.y),abs(q.x-q.z));
	return fmin<smin;
}
bool cmp2(sat p,sat q){
	ll fmin=min(abs(p.y-p.x),abs(p.y-p.z));
	ll smin=min(abs(q.y-q.x),abs(q.y-q.z));
	return fmin<smin;
}
bool cmp3(sat p,sat q){
	ll fmin=min(abs(p.z-p.x),abs(p.z-p.y));
	ll smin=min(abs(q.z-q.x),abs(q.z-q.y));
	return fmin<smin;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ll stan=n>>1,ans=0;
		fl=0;
		sl=0;
		tl=0;
		for(ll i=1;i<=3;i++) cnt[i]=0;
		for(ll i=1;i<=n;i++){
			fclub[i].x=0;
			fclub[i].y=0;
			fclub[i].z=0;
			sclub[i].x=0;
			sclub[i].y=0;
			sclub[i].z=0;
			tclub[i].x=0;
			tclub[i].y=0;
			tclub[i].z=0;
		}//chushihua
		for(ll i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y){
				if(a[i].x>a[i].z){
					cnt[1]++;
					fclub[++fl]=a[i];
				}else{
					cnt[3]++;
					tclub[++tl]=a[i];
				}
			}else{
				if(a[i].y>a[i].z){
					cnt[2]++;
					sclub[++sl]=a[i];
				}else{
					cnt[3]++;
					tclub[++tl]=a[i];
				}
			}
		}
		if(fl>stan){//ruguoclub1chaochu
			for(int i=1;i<=sl;i++){
				ans+=sclub[i].y;
			}
			for(int i=1;i<=tl;i++){
				ans+=tclub[i].z;
			}
			stable_sort(fclub+1,fclub+1+fl,cmp1);//genjuyuhoulianggeclubdechazhicongxiaodaodapaixu(xiatong)
			for(ll i=1;i<=fl-stan;i++){
				if(abs(fclub[i].x-fclub[i].y)>abs(fclub[i].x-fclub[i].z)){
					ans+=fclub[i].z;
				}else{
					ans+=fclub[i].y;
				}
			}
			for(ll i=fl-stan+1;i<=fl;i++){
				ans+=fclub[i].x;
			}
		}else if(sl>stan){//ruguoclub2chaochu
			for(int i=1;i<=fl;i++){
				ans+=fclub[i].x;
			}
			for(int i=1;i<=tl;i++){
				ans+=tclub[i].z;
			}
			stable_sort(sclub+1,sclub+1+sl,cmp2);
			for(ll i=1;i<=sl-stan;i++){
				if(abs(sclub[i].y-sclub[i].x)>abs(sclub[i].y-sclub[i].z)){
					ans+=sclub[i].z;
				}else{
					ans+=sclub[i].x;
				}
			}
			for(ll i=sl-stan+1;i<=sl;i++){
				ans+=sclub[i].y;
			}
		}else if(tl>stan){//ruguoclub3chaochu
			for(int i=1;i<=fl;i++){
				ans+=fclub[i].x;
			}
			for(int i=1;i<=sl;i++){
				ans+=sclub[i].y;
			}
			stable_sort(tclub+1,tclub+1+tl,cmp3);
			for(ll i=1;i<=tl-stan;i++){
				if(abs(tclub[i].z-tclub[i].x)>abs(tclub[i].z-tclub[i].y)){
					ans+=tclub[i].y;
				}else{
					ans+=tclub[i].x;
				}
			}
			for(ll i=tl-stan+1;i<=tl;i++){
				ans+=tclub[i].z;
			}
		}else{
			for(int i=1;i<=fl;i++){
				ans+=fclub[i].x;
			}
			for(int i=1;i<=sl;i++){
				ans+=sclub[i].y;
			}
			for(int i=1;i<=tl;i++){
				ans+=tclub[i].z;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
