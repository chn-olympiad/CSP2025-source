#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][5],ans;
int cnt[N],m1[N],m2[N],m3[N],sum[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t; 
    cin>>t;
    while(t--){
    	cin>>n;
    	memset(m1,-1,sizeof(m1));
    	memset(m3,0x7f,sizeof(m3));
    	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
		cin>>a[i][j];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				m1[i]=max(m1[i],a[i][j]);
				m3[i]=min(m3[i],a[i][j]);
			}
			sum[i]=a[i][1]+a[i][2]+a[i][3];
			m2[i]=sum[i]-m1[i]-m3[i];
		}
//		for(int i=1;i<=n;i++)
//		cout<<m1[i]<<" "<<m2[i]<<" "<<m3[i]<<"\n";
		sort(m1+1,m1+n+1,cmp);
		for(int i=1;i<=n/2;i++)
		for(int j=1;j<=n;j++)
		for(int k=1;k<=3;k++)
		if(m1[i]==a[j][k]) cnt[i]==1;
		for(int i=1;i<=n/2;i++)
		if(cnt[i]==1) m2[i]=0;
		sort(m2+1,m2+n+1,cmp);
		for(int i=1;i<=n/2;i++)
		ans+=(m1[i]+m2[i]);
		cout<<ans<<"\n";
	}
	return 0;
}
