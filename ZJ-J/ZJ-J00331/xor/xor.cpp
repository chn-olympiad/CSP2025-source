#include<bits/stdc++.h>
using namespace std;

const int maxx=5e5+4;
int n,k,a[maxx],cnt,ans,sum[maxx],dp[maxx];
map<int,int>mp;
struct st{
	int l,r;
}line[maxx];

bool cmp(st x,st y){
	if (x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if (a[i]==k) line[++cnt].l=line[cnt].r=i;
		else if (mp[sum[i]^k]){
			line[++cnt].l=mp[sum[i]^k];
			line[cnt].r=i;
		}
		mp[sum[i]]=i+1;
	}
	sort(line+1,line+cnt+1,cmp);
	for (int i=1;i<=cnt;i++){
		dp[i]=dp[i-1];
		for (int j=i-1;j>=0;j--){
			if (line[j].r<line[i].l) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	cout<<dp[cnt];
	return 0;
}
