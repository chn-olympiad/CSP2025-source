#include <bits/stdc++.h>
using namespace std;
const int N=5010; 
const int mod=998244353;
int n,a[N],b[N],t[N],maxn=-1<<30;
int dp[N],ans;
set<int> st; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
		t[a[i]]++;
	}
	sort(a,a+n);
	for(int i=maxn;i>=1;i--)
		b[i]=t[i]+b[i+1];
//	int l=1,r=1;
//	long long s=a[1];
//	for(int i=1;i<=n;i++){
//		if()
//	}
	for(int i=0;i<(1<<n);i++){
		int cnt=0,ls=0,num=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
//				cout<<j;
				num++;
				cnt+=a[j];
				ls=a[j];
			}
		}
//		cout<<endl;
		if(ls*2<cnt&&num>=3)ans++;
	}
	printf("%d\n",ans%mod);
	return 0;
}
