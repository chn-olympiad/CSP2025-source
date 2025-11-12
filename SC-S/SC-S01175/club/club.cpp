#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define int long long
int a[N][3],b[3][N],n,t,cnt[N],tmp[3];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;int ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			tmp[0]=a[i][0],tmp[1]=a[i][1],tmp[2]=a[i][2];
			sort(tmp,tmp+3);
			int d=tmp[2]-tmp[1];
			int mx=max(max(a[i][0],a[i][1]),a[i][2]);
			ans+=mx;
			if(mx==a[i][0]) b[0][++cnt[0]]=d;
			else if(mx==a[i][1]) b[1][++cnt[1]]=d;
			else if(mx==a[i][2]) b[2][++cnt[2]]=d;
		}
		int p=-1;
		if(cnt[0]>n/2) p=0;
		if(cnt[1]>n/2) p=1;
		if(cnt[2]>n/2) p=2;
		if(~p){
			sort(b[p]+1,b[p]+cnt[p]+1);
			for(int i=1;i<=cnt[p]-n/2;i++) 
				ans-=b[p][i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}