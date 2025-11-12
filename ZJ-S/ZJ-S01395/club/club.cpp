#include<iostream>
#include<algorithm>
using namespace std;
#define int long long

int cnt[3];
struct node{
	int a[3],flag;
}a[100010];
int res[100010];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ans=0;cnt[1]=cnt[2]=cnt[0]=0;
		for(int i=1;i<=n;i++) cin>>a[i].a[0]>>a[i].a[1]>>a[i].a[2];
		for(int i=1;i<=n;i++){
			if(a[i].a[0]>=a[i].a[1]){
				if(a[i].a[0]>=a[i].a[2]){
					cnt[0]++,a[i].flag=0,ans+=a[i].a[0];
				} else cnt[2]++,a[i].flag=2,ans+=a[i].a[2];
			} else {
				if(a[i].a[1]>=a[i].a[2]) cnt[1]++,a[i].flag=1,ans+=a[i].a[1];
				else cnt[2]++,a[i].flag=2,ans+=a[i].a[2];
			}
		}
		int pos=3;
		if(cnt[0]>n/2) pos=0;
		else if(cnt[1]>n/2) pos=1;
		else if(cnt[2]>n/2) pos=2;
		if(pos==3){cout<<ans<<'\n';continue;}
		int cur=0;
		for(int i=1;i<=n;i++){
			if(a[i].flag==pos){
				int mx=max(a[i].a[0],max(a[i].a[1],a[i].a[2])),mn=min(a[i].a[0],min(a[i].a[1],a[i].a[2]));
				res[++cur]=mx-(a[i].a[0]+a[i].a[1]+a[i].a[2]-mx-mn);
			}
		}
		sort(res+1,res+cur+1);
		for(int i=1;i<=cnt[pos]-n/2;i++) ans-=res[i];
		cout<<ans<<'\n';
	}
	return 0;
}
