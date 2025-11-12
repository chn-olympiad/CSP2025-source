#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;//¶à²âÒªÇå¿Õ£¡£¡£¡
#define int long long
int n;
const int N = 1e5+7;
int a[N][5];
int aaa[N];
int dfs(int now,int s1,int s2,int s3,int ans) {
	if(now==n+1)
	{
		if(s1+s2+s3==n)return ans;
		return 0;
	}
	
	int tte=0;
	if(s1!=n/2)
		tte=dfs(now+1,s1+1,s2,s3,ans+a[now][1]);
	if(s2!=n/2)
		tte=max(tte,dfs(now+1,s1,s2+1,s3,ans+a[now][2]));
	if(s3!=n/2)
		tte=max(tte,dfs(now+1,s1,s2,s3+1,ans+a[now][3]));
	return tte;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		scanf("%lld",&n);
		memset(a,0,sizeof(a));
		memset(aaa,0,sizeof(aaa));
		int ass=0;
		int a33=0;
		for(int i=1; i<=n; i++) {
			scanf("%lld %lld %lld",&a[i][1],&a[i][2],&a[i][3]);
			ass+=a[i][2]+a[i][3];
			a33+=a[i][3];
			aaa[i]=a[i][1];
		}
		if(ass!=0||n<=30) {
			cout<<dfs(1,0,0,0,0)<<endl;
		} else {
			if(ass==0) {
				int ans=0;
				sort(aaa+1,aaa+n+1);
				for(int i=n; i>n/2; i--) {
					ans+=aaa[i];
				}
				cout<<ans<<endl;
			}
		}
	
	}
	fclose(stdin);
		fclose(stdout);
	return 0;
}
