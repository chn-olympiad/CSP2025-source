#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long a[N];
long long n,k,maxn=0;
void dfs(long long dq,long long gs){
	//cout << dq-1;
	//cout << gs << endl;
	maxn=max(maxn,gs);
	long long yh;
	long long minn=10000005;
	for(long long j=dq;j<=n;j++){
		if(j>=minn) break;
		yh=0;
		for(long long i=j;i<=n;i++){
			//cout<< yh;
			yh=yh^a[i];
			if(yh==k){
				minn=min(minn,i);
				break;
			}
		}
	}
	if(minn!=10000005) dfs(minn+1,gs+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(long long i=1;i<=n;i++) cin >> a[i];
	if(k==1){
		long long ans=0;
		for(long long i=1;i<=n;i++){
			ans+=a[i];
		}
		cout << ans;
	}else{
		dfs(1,0);
		cout << maxn;
	}
	return 0;
}
