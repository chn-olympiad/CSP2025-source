#include<bits/stdc++.h>
using namespace std;
int t,n,a[5][100005],b[5][100005],cnt[5],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3;i++)b[i][0]=0,cnt[i]=0;ans=0;
		for(int i=1;i<=n;i++){
			int maxn=0,mi=1,max2=0;
			for(int j=1;j<=3;j++){
				cin>>a[j][i];
				if(a[j][i]>maxn)maxn=a[j][i],mi=j;
			}
			for(int j=1;j<=3;j++)if(j!=mi)max2=max(max2,a[j][i]);
			++cnt[mi],b[mi][++b[mi][0]]=maxn-max2,ans+=maxn;
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				sort(b[i]+1,b[i]+b[i][0]+1);
				for(int j=1;j<=cnt[i]-n/2;j++)ans-=b[i][j];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
