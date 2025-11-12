#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+100;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,k,ans=0;
	bool flag1=1;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag1=0;
	}
	if(flag1==1&&k==0){
		cout<<n/2<<'\n';
	}else{
		int q=0;
		for(long long i=1;i<=n;i++){
			long long u=q^a[i];
			if((u==k)){
			q=0;
				ans++;
			}else{
				q^=a[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
