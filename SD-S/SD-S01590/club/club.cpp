#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N][3],ans,cnt[3],val[N]; 
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n,ans=0,cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)cin>>a[i][j];
			int mx=0;
			if(a[i][1]>a[i][0])mx=1;
			if(a[i][2]>a[i][mx])mx=2;
			cnt[mx]++;
		}
		if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
			for(int i=1;i<=n;i++)ans+=max(a[i][0],max(a[i][1],a[i][2]));
			cout<<ans<<"\n";
			continue; 
		}
		for(int u=0;u<3;u++){
			int res=0;
			for(int i=1;i<=n;i++){
				int p=a[i][u],q=0;
				if(u)q=a[i][0];
				if(u!=1)q=max(q,a[i][1]);
				if(u!=2)q=max(q,a[i][2]);
				res+=q,val[i]=p-q;
			}
			sort(val+1,val+1+n),reverse(val+1,val+1+n); 
			for(int i=1;i<=n/2;i++)res+=val[i];
			ans=max(ans,res);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
