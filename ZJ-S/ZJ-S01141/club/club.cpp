#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+5;
int t,n,cnt[5],ans;
struct node{
	int p,f,s,cha;
}a[N];
bool cmp(node x,node y){
	return x.cha>y.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,cnt[1]=0,cnt[2]=0,cnt[3]=0;
		for(int i=1,b,c,d;i<=n;++i){
			cin>>b>>c>>d;
			if(b>=c&&c>=d){
				a[i].f=b;
				a[i].s=c;
				a[i].p=1;
			}
			else if(c>=b&&b>=d){
				a[i].f=c;
				a[i].s=b;
				a[i].p=2;
			}
			else if(b>=d&&d>=c){
				a[i].f=b;
				a[i].s=d;
				a[i].p=1;
			}
			else if(c>=d&&d>=b){
				a[i].f=c;
				a[i].s=d;
				a[i].p=2;
			}
			else if(d>=c&&c>=b){
				a[i].f=d;
				a[i].s=c;
				a[i].p=3;
			}
			else if(d>=b&&b>=c){
				a[i].f=d;
				a[i].s=b;
				a[i].p=3;
			}
			a[i].cha=a[i].f-a[i].s; 
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;++i){
			if(cnt[a[i].p]<n/2){
				cnt[a[i].p]++;
				ans+=a[i].f;
			}
			else{
				ans+=a[i].s;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
