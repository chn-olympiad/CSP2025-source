#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long n,s[4],ans,t,mx,tot,b[N];
struct node{
	long long a[4];
}d[N];
inline void solve(){
	s[1]=s[2]=s[3]=ans=tot=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i].a[1]>>d[i].a[2]>>d[i].a[3];
		if(d[i].a[1]>=d[i].a[2]&&d[i].a[1]>=d[i].a[3]) s[1]++,ans+=d[i].a[1];
		else if(d[i].a[2]>=d[i].a[3]) s[2]++,ans+=d[i].a[2];
		else s[3]++,ans+=d[i].a[3];
	}
	if(s[1]<=n/2&&s[2]<=n/2&&s[3]<=n/2){
		cout<<ans<<'\n';
		return ;
	}
	if(s[1]>n/2) t=1;
	else if(s[2]>n/2) t=2;
	else t=3;
	for(int i=1;i<=n;i++){
		if(d[i].a[t]>=d[i].a[1]&&d[i].a[t]>=d[i].a[2]&&d[i].a[t]>=d[i].a[3]){
			++tot;
			mx=0;
			for(int j=1;j<=3;j++){
				if(j==t) continue;
				mx=max(mx,d[i].a[j]);
			}
			b[tot]=d[i].a[t]-mx;
		}
	}
	sort(b+1,b+tot+1);
	for(int i=1;i<=s[t]-n/2;i++) ans-=b[i];
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
