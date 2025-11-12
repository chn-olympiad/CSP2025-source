#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
struct Student{
	ll x,y,z;
	pair<ll,ll>st,nd,rd;
}a[N];
bool cmp(Student p,Student q){
	ll gap1=p.st.second-p.nd.second;
	ll gap2=p.nd.second-p.rd.second;
	ll gaq1=q.st.second-q.nd.second;
	ll gaq2=q.nd.second-q.rd.second;
	if(gap1>gaq1)return true;
	else if(gap1==gaq1&&gap2>gaq2)return true;
	return false;
}
ll t,n,cnt[10],ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){  
		memset(cnt,0,sizeof(cnt));
		ans=0;
		scanf("%d",&n);
		for(ll i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			ll u=a[i].x,v=a[i].y,w=a[i].z;
			if(u>=v&&v>=w)a[i].st={1,u},a[i].nd={2,v},a[i].rd={3,w};
			else if(u>=w&&w>=v)a[i].st={1,u},a[i].nd={3,w},a[i].rd={2,v};
			else if(v>=u&&u>=w)a[i].st={2,v},a[i].nd={1,u},a[i].rd={3,w};
			else if(v>=w&&w>=u)a[i].st={2,v},a[i].nd={3,w},a[i].rd={1,u};
			else if(w>=u&&u>=v)a[i].st={3,w},a[i].nd={1,u},a[i].rd={2,v};
			else a[i].st={3,w},a[i].nd={2,v},a[i].rd={1,u};
		}
		sort(a+1,a+1+n,cmp);
		for(ll i=1;i<=n;i++){
			if(cnt[a[i].st.first]>=n/2){
				if(cnt[a[i].nd.first]>=n/2){
					ans+=a[i].rd.second;
					cnt[a[i].rd.first]++;
				}
				else{
					ans+=a[i].nd.second;
					cnt[a[i].nd.first]++;
				}
			}
			else{
				ans+=a[i].st.second;
				cnt[a[i].st.first]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}