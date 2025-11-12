#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],dp[1000][1000];
int ans,tmp,cnt1;
map <int,int> m;
bool aiEQ1=true,aiLESS1=true;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
		if(i<1000) {
			dp[i][i]=a[i];
		}
		if(a[i]==1)cnt1++;
		if(a[i]>1)aiLESS1=false;
		if(a[i]!=1)aiEQ1=false;
	}
	if(aiEQ1 and k==0) {
		printf("%d",n/2);
		return 0;
	}
	if(aiLESS1) {
		if(k==0) {
			printf("%d",cnt1/2);
			return 0;
		}
		if(k==1) {
			printf("%d",cnt1);
			return 0;
		}
	}
	for(int len=1; len<n; len++) {
		for(int l=0; l+len<n; l++) {
			if(l+len>=n)break;
			dp[l][l+len]=dp[l][l+len-1]^a[l+len];
//			cout<<"dp["<<l<<"]["<<l+len<<"]="<<dp[l][l+len]<<endl;
		}
	}
	for(int x=0; x<n; x++) {
		if(m.find(x)==m.end() or x==0) {
			for(int y=x; y<n; y++) {
				if(dp[x][y]==k and m.find(y)==m.end()) {
					for(int xx=x; xx<=y; xx++)m[tmp++]=xx;
					ans++;
					break;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}