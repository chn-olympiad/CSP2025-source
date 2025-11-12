#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500010];
int sum[500010];
int lst[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	memset(lst,-1,sizeof(lst));
	lst[0]=0;
	int ans=0,llst=-1;
	for(int i=1;i<=n;i++){
		int t=sum[i]^k;
		if(lst[t]!=-1&&lst[t]>=llst){
			ans++;
			llst=i;
		}
		lst[sum[i]]=i;
	}
	cout<<ans;
	return 0;
}

