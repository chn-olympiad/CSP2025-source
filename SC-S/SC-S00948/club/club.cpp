#include<bits/stdc++.h>
using namespace std;

long long t;
long long n;
long long a[4];
long long r[4];
long long ans;
long long s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(long long i=1;i<=t;i++){
		scanf("%lld",&n);
		ans=0;
		s=n/2;
		for(long long j=1;j<=n;j++){
			scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
			if(max(a[1],max(a[2],a[3]))==a[1]&&r[1]+1<=s){
				ans+=a[1];
				r[1]++;
			}else if(max(a[1],max(a[2],a[3]))==a[2]&&r[2]+1<=s){
				ans+=a[2];
				r[2]++;
			}else if(max(a[1],max(a[2],a[3]))==a[3]&&r[3]+1<=s){
				ans+=a[3];
				r[3]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}