#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],b[500010],t,maxx;
bool f;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i){
		int m=a[i];
		if(m==k){
			b[i]=i;
			continue;
		}
		for(int j=i+1;j<=n;++j){
			m=m^a[j];
			if(m==k){
				b[i]=j;
				break;
			}
		}
	}
	t=1,f=1;
	while(f){
		int minn=LLONG_MAX,w;
		f=0;
		for(int i=t;i<=n;++i){
			if(b[i]!=0&&b[i]<minn){
				minn=b[i];
				w=i;
			}
			if(i>minn)break;
		}
		if(minn!=LLONG_MAX){
			t=b[w]+1;
			f=1;
			++maxx;
		}
	}
	printf("%lld",maxx);
}