//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long
#define N 100005
#define M 105
using namespace std;
int k[N][3];
int n;
map<pair<pair<int,int>,pair<int,int> >,int>dp;
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	for(int o=1; o<=T; o++) {
		cin>>n;
		//memset(dp,0,sizeof(dp));
		dp.clear();
		//st.clear();
		memset(k,0,sizeof(k));
		int h=0,f=0;
		for(int i=1; i<=n; i++) {
			cin>>k[i][0]>>k[i][1]>>k[i][2];
			h+=k[i][0];
			if(k[i][1]||k[i][2])f=1;
		}
		if(!f)cout<<h<<"\n";
		else {
			for(int a=n/2; a>=0; a--) {
				for(int b=n/2; b>=0; b--) {
					for(int c=n/2; c>=0; c--) {
						if((n/2+n/2+n/2)-a-b-c>n)continue;
						pair<pair<int,int>,pair<int,int> >uu;
						pair<int,int>vv;
						vv.first=a,vv.second=b;
						uu.first=vv;
						vv.first=c;
						vv.second=n;
						uu.second=vv;
						if(a) {
							dp[uu]=max(dp[uu],k[n][0]);
						}
						if(b) {
							dp[uu]=max(dp[uu],k[n][1]);
						}
						if(c) {
							dp[uu]=max(dp[uu],k[n][2]);
						}
					}
				}
			}
			for(int i=n-1; i>=1; i--) {
				for(int a=n/2; a>=0; a--) {
					for(int b=n/2; b>=0; b--) {
						for(int c=n/2; c>=0; c--) {
							if((n/2+n/2+n/2)-a-b-c>n)continue;
							pair<pair<int,int>,pair<int,int> >uu;
							pair<int,int>vv;
							vv.first=a,vv.second=b;
							uu.first=vv;
							vv.first=c;
							vv.second=i;
							uu.second=vv;
							if(a) {
								pair<pair<int,int>,pair<int,int> >u;
								pair<int,int>v;
								v.first=a-1,v.second=b;
								u.first=v;
								v.first=c;
								v.second=i+1;
								u.second=v;
								dp[uu]=max(dp[uu],dp[u]+k[i][0]);
							}
							if(b) {
								pair<pair<int,int>,pair<int,int> >u;
								pair<int,int>v;
								v.first=a,v.second=b-1;
								u.first=v;
								v.first=c;
								v.second=i+1;
								u.second=v;
								dp[uu]=max(dp[uu],dp[u]+k[i][1]);
							}
							if(c) {
								pair<pair<int,int>,pair<int,int> >u;
								pair<int,int>v;
								v.first=a,v.second=b;
								u.first=v;
								v.first=c-1;
								v.second=i+1;
								u.second=v;
								dp[uu]=max(dp[uu],dp[u]+k[i][2]);
							}

							//cout<<a<<" "<<b<<" "<<c<<" "<<dp[uu]<<"\n";
						}
					}
				}
			}
			pair<pair<int,int>,pair<int,int> >u;
			pair<int,int>v;
			v.first=n/2,v.second=n/2;
			u.first=v;
			v.first=n/2;
			v.second=1;
			u.second=v;
			cout<<dp[u]<<"\n";
		}
	}

	return 0;
}
/*
1 <=t<=5;
2<=n<=1e5 n%2==0
0<=a[i][j]<=2e4
*/
