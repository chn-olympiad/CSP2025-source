#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100009][4];
int ans=0;
int mas[100009],mad[100009];
inline void solve(){
	cin>>n;
	int z[5]={0,0,0};ans=0;
	for(int i=1;i<=n;i++){
		int x,y,zz;scanf("%lld%lld%lld",&x,&y,&zz);
		a[i][0]=x,a[i][1]=y,a[i][2]=zz;
		int ma=max(x,max(y,zz));mas[i]=ma;
		if(ma==a[i][0]) z[0]++,mad[i]=0;
		else if(ma==a[i][1]) z[1]++,mad[i]=1;
		else z[2]++,mad[i]=2;ans+=ma;
	}
	
	if(max(z[0],max(z[1],z[2]))<=n/2){
		cout<<ans<<'\n';return;
	}
	vector<int> ch;
	int zz=-1,cc=0;
	for(int i=0;i<=2;i++) if(z[i]>n/2) zz=i,cc=(z[i]-n/2);
	for(int i=1;i<=n;i++){
		if(mad[i]==zz) {
			int mi=1e14;
			for(int j=0;j<=2;j++){
				if(j==mad[i]) continue;
				mi=min(mi,mas[i]-a[i][j]);
			}
			ch.push_back(mi);
		}
	}
	sort(ch.begin(),ch.end());
	for(int i=0;i<cc;i++) ans-=ch[i];
	cout<<ans<<'\n';
	
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--) solve();
	return 0;
}
