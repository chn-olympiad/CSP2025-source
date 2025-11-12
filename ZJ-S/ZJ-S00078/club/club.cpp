#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=300;
LL val[maxn],s1,ans,flag,s2,s3,n,i,T,k,ma,t,j,dp[300][200][200];
struct  no{
	LL x,y,z;
};
no a[maxn];
bool cmp(no q,no h){
	return q.x>h.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		ma=0;
		if(n<=200){
			for(t=1;t<=n;t++)
				for(i=0;i<=min(t,n/2);i++)
					for(j=0;j<=min(t,n/2);j++){
						k=t-i-j;
						if(k<0||k>n/2) continue;
						s1=s2=s3=-1;
						if(i) s1=dp[t-1][i-1][j]+a[t].x;
						if(j) s2=dp[t-1][i][j-1]+a[t].y;
						if(k) s3=dp[t-1][i][j]+a[t].z;
						dp[t][i][j]=max(s1,max(s2,s3));
						if(t==n) ma=max(ma,dp[t][i][j]);
					}
			cout<<ma<<"\n";
		}
		else{
			flag=0;
			for(i=1;i<=n;i++)
				if(a[i].y!=0||a[i].z!=0) flag=1;
			if(flag==0){
				ans=0;
				sort(a+1,a+1+n,cmp);
				for(i=1;i<=n/2;i++)
					ans+=a[i].x;
				cout<<ans<<"\n";
			}
		}
	}	
	return 0;
}
/*
Ren5Jie4Di4Ling5%
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
