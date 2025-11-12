#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	long long now=0,bb,cnt;
	for(int i=1;i<=n;i++){
		cnt=a[i];
		bb=i;
		while(cnt!=k){
			if(bb<=now) break;
			bb--;
			cnt=cnt^a[bb];
			if(bb<=now){
				cnt=k-1;
				break;
			}
		}
		if(cnt==k){
			ans++;
			now=i;
		}
	}
	cout<<ans;
	return 0;
}