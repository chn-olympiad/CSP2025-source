#include<bits/stdc++.h>
using namespace std;
const int N=5001;
int a[N],n,ans;
bool vis[N];
int bit_cnt(long long x){
	int cnt=0;
	while(x){
		cnt+=(x&1);
		x>>=1;
	}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	long long x=(1<<n);
	for(long long i=0;i<x;++i){
		if(bit_cnt(i)>=3){
			long long j=i,cnt=0;
			while(j){
				++cnt;
				vis[cnt]=j&1;
				j>>=1;
			}
			int mx=-1,sum=0;
			for(int k=1;k<=n;++k){
				if(vis[k]){
					mx=max(mx,a[k]);
					sum+=a[k];
				}
			}
			if(sum>mx*2) ans=(ans+1)%998244353;
		}
	}
	cout<<ans;
	return 0;
}
