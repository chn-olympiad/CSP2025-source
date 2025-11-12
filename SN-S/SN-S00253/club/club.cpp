// SN-S00253  张笑语  西安高新第一中学
#include<bits/stdc++.h>
#define ll long long
#define il inline

using namespace std;
namespace asbt{
const int maxn=1e5+5;
int T,n,a[maxn][3],b[maxn],c[maxn];
int main(){
//	system("fc club5.ans my.out");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int cnt0=0,cnt1=0,cnt2=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int t=max({a[i][0],a[i][1],a[i][2]});
			ans+=t;
			if(t==a[i][0]){
				b[i]=0,cnt0++;
			}else if(t==a[i][1]){
				b[i]=1,cnt1++;
			}else{
				b[i]=2,cnt2++;
			}
		}
		int cnt=max({cnt0,cnt1,cnt2});
		if(cnt<=n>>1){
			cout<<ans<<'\n';
		}else{
			int p=cnt==cnt0?0:cnt==cnt1?1:2;
			for(int i=1,tot=0;i<=n;i++){
				if(b[i]==p){
					c[++tot]=(p==0?max(a[i][1],a[i][2]):p==1?max(a[i][0],a[i][2]):max(a[i][0],a[i][1]))-a[i][p];
				}
			}
			sort(c+1,c+cnt+1,greater<>());
			for(int i=1;i<=cnt-n/2;i++){
				ans+=c[i];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
}
int main(){return asbt::main();}

