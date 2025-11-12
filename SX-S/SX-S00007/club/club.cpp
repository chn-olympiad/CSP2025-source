#include<bits/stdc++.h>
#define int long long
#define FREOPEN(x) freopen(x ".in","r",stdin),freopen(x ".out","w",stdout);
using namespace std;
int v2[100005],v[3][100005];
bool cmp(int a,int b) {
	return a>b;
} signed main() {
	FREOPEN("club")
	int T;
	cin>>T;
	while(T--) {
		memset(v,0,sizeof(v));
		int n,m,sum=0,flag1=1,flag2=1;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>v[1][i]>>v[2][i]>>v[3][i];
			if(v[2][i]!=0) {
				flag1=0;
			} if(v[3][i]!=0) {
				flag2=0;
			}
		} if(flag1&&flag2) {
			for(int i=1;i<=n;i++) {
				v2[i]=v[1][i];
			} sort(v2+1,v2+n+1,cmp);
			for(int i=1;i<=n/2;i++) {
				sum+=v2[i];
			} cout<<sum<<endl;
		} if(n==2) {
			int ans=INT_MIN;
			for(int i=1;i<=3;i++) {
				for(int j=1;j<=3&&j!=i;j++) {
					ans=max(ans,v[1][i]+v[2][j]);
				}
			} cout<<ans<<endl;
		}
	} return 0;
}