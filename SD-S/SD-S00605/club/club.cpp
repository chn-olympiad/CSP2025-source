#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9,M=5e4+9,INF=998244353;
ll n,ans,c[5],maxx[N],cnt;
struct node {
	int a,b,c;
	int max1,max2,maxi;
} s[N];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--) {
		ans=0;
		memset(maxx,0,sizeof(maxx));
		memset(s,0,sizeof(s));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].max1=max(s[i].a,max(s[i].b,s[i].c));
			if(s[i].max1==s[i].a) {
				s[i].a=0;
				s[i].maxi=1;
				s[i].max2=max(s[i].b,s[i].c);
			}else if(s[i].max1==s[i].b) {
				s[i].b=0;
				s[i].maxi=2;
				s[i].max2=max(s[i].a,s[i].c);
			}else{
				s[i].c=0;
				s[i].maxi=3;
				s[i].max2=max(s[i].a,s[i].b);
			}
			maxx[i]=s[i].max1-s[i].max2;
		}
		sort(maxx+1,maxx+n+1);
		for(int i=1;i<=n;i++){
			ans+=s[i].max1;
			c[s[i].maxi]++;
		}
		for(int i=1;i<=3;i++){
			if(c[i]>n/2){
				for(int j=1;j<=c[i]-n/2;j++){
					ans-=maxx[j];
				}
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
