#include<bits/stdc++.h>
using namespace std;
struct nnd{
	int ll,rr;
}ans[500010];
int n,k,tp;
int sum[500010],a[500010],dp[500010],js[2500000];
vector<int> bx[2500000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i],js[sum[i]]++;
		bx[sum[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int dy=k^sum[i-1];
		if(js[dy]>0){
			int l=0,r=bx[dy].size()-1,tt=0;
			while(l<r){
				int md=l+r>>1;
				if(bx[dy][md]>=i) r=md;
				else l=md+1;
			}
			ans[++tp].ll=i,ans[tp].rr=bx[dy][l];
		}
		js[sum[i]]--;
	}
	int cnt=1;
	for(int i=2;i<=tp;i++){
		if(ans[i].ll<=ans[i-1].rr){
			if(ans[i].rr>ans[i-1].rr) ans[i]=ans[i-1];
		}
		else cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
