//SN-S00061  Liu Yuhe  School:Fengdong  kaodian:Binhe
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;long long ans;
int t,n,a[N][3],id[N],num[3],dl[N];
priority_queue<int>q;
inline void solve(){
	cin>>n,num[0]=num[1]=num[2]=ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			id[i]=0,ans+=a[i][0],num[0]++;
			dl[i]=a[i][0]-max(a[i][1],a[i][2]);
		}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			id[i]=1,ans+=a[i][1],num[1]++;
			dl[i]=a[i][1]-max(a[i][0],a[i][2]);
		}else{
			id[i]=2,ans+=a[i][2],num[2]++;
			dl[i]=a[i][2]-max(a[i][0],a[i][1]);
		}
	}for(int i=0;i<3;i++) if(num[i]>n/2){
		while(q.size()) q.pop();
		for(int j=1;j<=n;j++) if(id[j]==i) q.push(-dl[j]);
		while((int)q.size()>n/2) ans+=q.top(),q.pop();
	}cout<<ans<<"\n";
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0),cin>>t;
	while(t--) solve();
	return 0;
}
