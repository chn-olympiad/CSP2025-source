#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n ,m,a[100100][4],d[100100],t,s[4];
bool maxx(int aa,int bb){
	for(int i=1;i<=3;i++){
		if(i!=aa){
			if(a[bb][aa]<a[bb][i])return false;
		}
	}return true;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int hg=1,ans;hg<=t;hg++){
		ans=0;
		cin>>n;m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			s[2]=s[1]=s[3]=0;
		}
		for(int i=1;i<=n;i++){
//			dp[i][0]=
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				s[1]++;ans+=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				s[2]++;ans+=a[i][2];
			}
			else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				s[3]++;ans+=a[i][3];
			}
		} 
//		cout<<ans<<"\n";
		if(s[1]<=m&&s[2]<=m&&s[3]<=m)cout<<ans<<"\n";
		else{
			int mii;
			if(s[1]>m){
				mii=1;
			}else if(s[2]>m){
				mii=2;
			}else if(s[3]>m){
				mii=3;
			}int ii=0;
			for(int i=1;i<=n;i++){
				if(maxx(mii,i)){
					
					int maxn=-pow(2,30);
					for(int j=1;j<=3;j++){
						if(j!=mii){
							maxn=max(maxn,a[i][j]);
						}
					}
					if(maxn<-pow(2,29)){
						if(mii==2)maxn=a[i][3];
						else maxn=a[i][2];
					}
					d[++ii]=a[i][mii]-maxn;
				}
			}
			sort(d+1,d+ii+1);
			for(int i=1;i<=ii-m;i++){
				ans-=d[i];
				
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}


//100
