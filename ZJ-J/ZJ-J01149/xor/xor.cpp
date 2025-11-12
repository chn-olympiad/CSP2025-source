#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],x[500005],sum,ans;
struct ggg{
	long long ll,rr;
}can[500005];
bool cmp(ggg a,ggg b){
	return a.rr<b.rr||a.rr==b.rr&&a.ll>b.ll;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);x[i]=x[i-1]^a[i];
	}
	for(int p=1;p<=n;p++){
		for(int q=p;q<=n;q++){
			if((x[q]^x[p-1])==k)can[++sum]={p,q};
		}
	}
	sort(can+1,can+sum+1,cmp);
	int last=0;
	for(int i=1;i<=sum;i++){
		if(can[i].ll>last)ans++,last=can[i].rr;
	}printf("%lld",ans);
	return 0;
}

