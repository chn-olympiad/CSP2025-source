#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
ll n,k,a[maxn],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=n;){
		if(a[i]==k){
			ans++;
			i++;
			continue;
		}
		ll temp=a[i];
		int pos=-1;
		for(int j=i+1;j<=n;j++){
			temp^=a[j];
			if(temp==k){
				ans++;
				pos=j;
				break;
			}
		}
		if(pos==-1) i++;
		else i=pos+1;
	}
	printf("%lld",ans);
	return 0;
}
