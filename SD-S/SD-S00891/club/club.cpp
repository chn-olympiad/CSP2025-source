#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int T;
int n;
struct node {
	int a,b,c;
	int mx=0;
} a[100005];
bool cmp(node a,node b) {
	return a.mx>b.mx;
}
bool cmp2(node a,node b) {
	return abs(a.a-a.b)>abs(b.a-b.b);
}
int gt(int i,int j) {
	if(j==1)return a[i].a;
	if(j==2)return a[i].b;
	if(j==3)return a[i].c;
}
int dp[202][202][202];
int s[100005][5][5];
int f[100005][5];
int ff[202][202];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		int flg=1,t=n/2,ans=0,flg2=1;
		for(int i=1; i<=n; i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].mx=max(max(a[i].a,a[i].b),a[i].c);
			if(a[i].b!=a[i].c||a[i].b!=0||a[i].c!=0)flg=0;
			if(a[i].c)flg2=0;
		}
		if(flg) {
			sort(a+1,a+n+1,cmp);
			for(int i=1; i<=t; i++) {
				ans+=a[i].mx;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(flg2) {
			if(n<=200) {
				memset(ff,0,sizeof(ff));
				for(int i=1; i<=n; i++) {
					for(int j=t; j>=0; j--) {
						for(int k=t; k>=0; k--) {
							if(j>=1)
								ff[j][k]=max(ff[j][k],ff[j-1][k]+a[i].a);
							if(k>=1)
								ff[j][k]=max(ff[j][k],ff[j][k-1]+a[i].b);
						}
					}
				}
				for(int j=t; j>=0; j--) {
					for(int k=t; k>=0; k--) {
						if(j+k==n)
							ans=max(ans,ff[j][k]);
					}
				}
				cout<<ans<<"\n";
			} else {
				sort(a+1,a+n+1,cmp2);
				int sa,sb;
				sa=sb=0;
				for(int i=1; i<=n; i++) {
					if(a[i].mx==a[i].a&&sa<t) {
						sa++;
						ans+=a[i].mx;
					} else if(a[i].mx==a[i].b&&sb<t) {
						sb++;
						ans+=a[i].mx;
					} else {
						if(sa<t) {
							sa++;
							ans+=a[i].mx;
						} else if(sb<t) {
							sb++;
							ans+=a[i].mx;
						}
					}
				}
				cout<<ans<<"\n";
			}
			continue;
		}
		if(n>=200) {
			memset(f,-1,sizeof(f));
			f[0][1]=f[0][2]=f[0][3]=0;
			memset(s,0,sizeof(s));
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=3; j++) {
					int tt=0;
					for(int k=1; k<=3; k++) {
						if(s[i-1][k][j]<t) {
							if(f[i][j]<f[i-1][k]+gt(i,j)) {
								f[i][j]=f[i-1][k]+gt(i,j);
								tt=k;
							}
						}
					}
					s[i][j][1]=s[i-1][tt][1];
					s[i][j][2]=s[i-1][tt][2];
					s[i][j][3]=s[i-1][tt][3];
					s[i][j][j]++;
					ans=max(ans,f[i][j]);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=n; i++) {
			for(int j=t; j>=0; j--) {
				for(int k=t; k>=0; k--) {
					for(int h=t; h>=0; h--) {
						if(j>=1)
							dp[j][k][h]=max(dp[j][k][h],dp[j-1][k][h]+a[i].a);
						if(k>=1)
							dp[j][k][h]=max(dp[j][k][h],dp[j][k-1][h]+a[i].b);
						if(h>=1)
							dp[j][k][h]=max(dp[j][k][h],dp[j][k][h-1]+a[i].c);
					}
				}
			}
		}
		for(int j=t; j>=0; j--) {
			for(int k=t; k>=0; k--) {
				for(int h=t; h>=0; h--) {
					if(j+k+h==n)
						ans=max(ans,dp[j][k][h]);
				}

			}
		}
		
		cout<<ans<<"\n";
	}

	return 0;
}

