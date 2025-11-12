#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
using namespace std;
const int N=1e5+5;
int _,n,x,y,z,a[N],w[N],b[N],ct,ans,c[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>_;
	while(_--){
		cin>>n;ans=0;
		c[0]=c[1]=c[2]=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			ans+=max({x,y,z});
			if(x>=y&&x>=z)c[w[i]=0]++,a[i]=x-max(y,z);
			else if(y>=x&&y>=z)c[w[i]=1]++,a[i]=y-max(x,z);
			else c[w[i]=2]++,a[i]=z-max(x,y);
		}
		int p=-1;
		for(int i=0;i<3;i++)if(c[i]>n/2)p=i;
		if(!~p){cout<<ans<<'\n';continue;}
		ct=0;
		for(int i=1;i<=n;i++)if(w[i]==p)b[++ct]=a[i];
		sort(b+1,b+ct+1);
		for(int i=1;i<=c[p]-n/2;i++)ans-=b[i];
		cout<<ans<<'\n';
	}
	//cerr<<1.*clock()/CLOCKS_PER_SEC<<'\n';
	return 0;
}
// 14:45
// Ren5Jie4Di4Ling5%