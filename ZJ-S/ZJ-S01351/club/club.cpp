#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,i,j,k,t,T,ma,ma2,ma3,ans,ans1,ans2,t1,t2,f[3][110][110][110];
struct no{
	int one,two,three;
}a[100010];
bool cmp(no q,no h){
	return q.one>h.one;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		cin>>n;ma=0;
		for(i=0;i<=n/2;i++)
			for(j=0;j<=n/2;j++){
				k=t-i-j;
				if(k<0)continue;
				f[1][i][j][k]=0;
				f[0][i][j][k]=0;
			}
		for(i=1;i<=n;i++)
			cin>>a[i].one>>a[i].two>>a[i].three,ma3=max(ma3,a[i].three),ma2=max(ma2,a[i].two);
		if(ma3==0){
			if(ma2==0){
				sort(a+1,a+1+n,cmp);
				for(i=1;i<=n/2;i++)
					ans+=a[i].one;
				cout<<ans<<"\n";
			}
			continue;
		}
		for(t=1;t<=n;t++)
			for(i=0;i<=min(t,n/2);i++)
				for(j=0;j<=min(t-i,n/2);j++){
					k=t-i-j;
					if(k>n/2)continue;
					if(i!=0)f[t&1][i][j][k]=max(f[t&1][i][j][k],f[1-(t&1)][i-1][j][k]+a[t].one);
					if(j!=0)f[t&1][i][j][k]=max(f[t&1][i][j][k],f[1-(t&1)][i][j-1][k]+a[t].two);
					if(k!=0)f[t&1][i][j][k]=max(f[t&1][i][j][k],f[1-(t&1)][i][j][k-1]+a[t].three);
					ma=max(ma,f[t&1][i][j][k]);
				}
		cout<<ma<<"\n";
	}
	return 0;
}
