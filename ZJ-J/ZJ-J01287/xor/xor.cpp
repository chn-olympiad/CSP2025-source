#include<bits/stdc++.h>
using namespace std;
int a[501005],n,k;
pair<int,int> b[501005];
int g[1100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	memset(g,-1,sizeof(g));
	int cnt=0;
	for(int i=n;i>=1;i--){
		g[a[i]]=i;
		if(g[a[i-1]^k]!=-1){
			b[++cnt]=make_pair(g[a[i-1]^k],i);
		}
	}
	sort(b+1,b+cnt+1);
	int ans=0,r=0;
	for(int i=1;i<=cnt;i++){
		if(b[i].second>r){
			ans++;
			r=b[i].first;
		}
	}
	printf("%d",ans);
	return 0;
}
