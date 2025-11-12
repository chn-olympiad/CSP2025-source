#include<bits/stdc++.h>
#define N 500005
using namespace std;
long long xr(long long a,long long b){
	if(a<b) swap(a,b);
	long long res=0,nw=1;
	while(a>0){
		if(a%2!=b%2) res+=nw;
		nw*=2;
		a/=2,b/=2;
	}
	return res;
}
map<long long,long long> mp;
long long sum[N],a[N],n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	//cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		//cin>>a[i];
		sum[i]=xr(sum[i-1],a[i]);
	}
	long long lst=1;
	long long id;
	for(int i=1;i<=n;i++){
		mp[sum[i]]=i;
		//cout<<i<<" "<<sum[i];
		if(a[i]==k){
			//cout<<"A\n";
			lst=i;
			ans++;
			continue;
		}
		//cout<<" "<<xr(sum[i],k)<<" "<<mp[xr(sum[i],k)];
		id=mp[xr(sum[i],k)];
		if(id>=lst and id<i){
			//cout<<"B\n";
			lst=i;
			ans++;
			continue;
		}
		if(sum[i]==k and ans==0){
			//cout<<"C\n";
			lst=i;
			ans++;
			continue;
		}
		//cout<<endl;
	}
	//cout<<endl;
	printf("%lld",ans);
//	cout<<ans;
	return 0;
}