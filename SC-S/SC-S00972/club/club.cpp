#include<bits/stdc++.h>
using namespace std;
struct s{
	int n1,n2,n3;
	int maxx,id;
}a[100006];
int t,n,dp[100006][16],cnt[6],tmp[4];
bool cad[16];
bool cmp(s x,s y){
	return x.maxx>y.maxx;
}
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cad[1]=cad[2]=cad[3]=true;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=100006;i++) for(int j=1;j<=3;j++) dp[i][j]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].n1>>a[i].n2>>a[i].n3;
			a[i].maxx=max(a[i].n1,max(a[i].n2,a[i].n3));
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(cad[1]) dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].n1;
			if(cad[2]) dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].n2;
			if(cad[3]) dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].n3;
			int mx=-1e9,mxid=0;
			for(int j=1;j<=3;j++) if(mx<dp[i][j]) mxid=j,mx=dp[i][j];
			cnt[mxid]++;
			if(cnt[1]==n/2) cad[1]=false;
			if(cnt[2]==n/2) cad[2]=false;
			if(cnt[3]==n/2) cad[3]=false;
		}
		int ans=max(dp[n][1],max(dp[n][2],dp[n][3]));
		cad[1]=cad[2]=cad[3]=true;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			int cd=-1e9;
			tmp[1]=dp[i-1][1];tmp[2]=dp[i-1][2];tmp[3]=dp[i-1][3];
			sort(tmp+1,tmp+4);
			cd=tmp[2];
			if(cad[1]) dp[i][1]=cd+a[i].n1;
			if(cad[2]) dp[i][2]=cd+a[i].n2;
			if(cad[3]) dp[i][3]=cd+a[i].n3;
			tmp[1]=dp[i][1];tmp[2]=dp[i][2];tmp[3]=dp[i][3];
			sort(tmp+1,tmp+4);
			cnt[(tmp[2]==dp[i][1]?1:(tmp[2]==dp[i][2]?2:3))]++;
			if(cnt[1]==n/2) cad[1]=false;
			if(cnt[2]==n/2) cad[2]=false;
			if(cnt[3]==n/2) cad[3]=false;
		}
		ans=max(ans,max(dp[n][1],max(dp[n][2],dp[n][3])));
		cad[1]=cad[2]=cad[3]=true;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			int cd=0;
			tmp[1]=dp[i-1][1];tmp[2]=dp[i-1][2];tmp[3]=dp[i-1][3];
			sort(tmp+1,tmp+4);
			cd=tmp[1];
			if(cad[1]) dp[i][1]=cd+a[i].n1;
			if(cad[2]) dp[i][2]=cd+a[i].n2;
			if(cad[3]) dp[i][3]=cd+a[i].n3;
			tmp[1]=dp[i][1];tmp[2]=dp[i][2];tmp[3]=dp[i][3];
			sort(tmp+1,tmp+4);
			cnt[(tmp[1]==dp[i][1]?1:(tmp[1]==dp[i][2]?2:3))]++;
			if(cnt[1]==n/2) cad[1]=false;
			if(cnt[2]==n/2) cad[2]=false;
			if(cnt[3]==n/2) cad[3]=false;
		}
		ans=max(ans,max(dp[n][1],max(dp[n][2],dp[n][3])));
		cout<<ans<<endl;
	}
	return 0;
}