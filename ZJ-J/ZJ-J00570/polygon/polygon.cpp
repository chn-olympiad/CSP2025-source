#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
#define int long long
int a[5100],mp[5100];
int z,sum=0,n,ans;
void bfs(int x,int z){
	if(x==0){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			if(mp[i]){
				maxx=max(maxx,a[i]);
			}
		}
		if(maxx*2<sum) ans++;
		return;
	}
	for(int i=z;i<=n;i++){
		if(mp[i]==0){
			sum+=a[i];
			mp[i]=1;
			bfs(x-1,i+1);
			mp[i]=0;
			sum-=a[i];
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		z=i;
		bfs(i,1);
	}
	cout<<ans;
	return 0;
}

