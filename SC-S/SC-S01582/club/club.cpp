#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
struct node{
	int a,b,c,mx,se;
}a[N];
int T,n,ans,cnt[4];
vector<int> s;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		s.clear();
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].mx=max({a[i].a,a[i].b,a[i].c});
			if(a[i].mx==a[i].a){
				a[i].se=max(a[i].b,a[i].c);
				cnt[1]++;
			}else if(a[i].mx==a[i].b){
				a[i].se=max(a[i].a,a[i].c);
				cnt[2]++;
			}else{
				a[i].se=max(a[i].a,a[i].b);
				cnt[3]++;
			}
		}
		if(cnt[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].mx==a[i].a){
					s.emplace_back(a[i].mx-a[i].se);
					ans+=a[i].se;
				}
				else ans+=a[i].mx;
			}
			sort(s.begin(),s.end(),greater<int>());
			for(int i=0;i<n/2;i++)ans+=s[i];
		}else if(cnt[2]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].mx==a[i].b){
					s.emplace_back(a[i].mx-a[i].se);
					ans+=a[i].se;
				}
				else ans+=a[i].mx;
			}
			sort(s.begin(),s.end(),greater<int>());
			for(int i=0;i<n/2;i++)ans+=s[i];
		}else if(cnt[3]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].mx==a[i].c){
					s.emplace_back(a[i].mx-a[i].se);
					ans+=a[i].se;
				}
				else ans+=a[i].mx;
			}
			sort(s.begin(),s.end(),greater<int>());
			for(int i=0;i<n/2;i++)ans+=s[i];
		}else{
			for(int i=1;i<=n;i++)ans+=a[i].mx;
		}
		cout<<ans<<'\n';
	}
	return 0;
}