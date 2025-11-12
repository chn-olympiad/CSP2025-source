#include <bits/stdc++.h>
using namespace std;
const long long N=5005;
long long a[N];
struct S{
	long long sum,mx;
	long long sz;
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin >> n;
	long long maxn=0;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(n<=2) cout <<0;
		else if(a[1]+a[2]>a[3]) cout << 1;
		else cout << 0;
		return 0;
	}
	if(maxn==1){
		long long gs=0,dq=n*(n-1)*(n-2),dq2=6;
		gs+=dq/dq2;
		for(long long k=4;k<=n;k++){
			dq*=(n-k+1);
			dq2*=k;
			gs=(gs+dq/dq2)%998244353;
		}
		cout << gs;
		return 0;
	}else if(n<=20){
		vector<S> g;
		long long sz;
		long long ans=0;
		for(long long i=1;i<=n;i++){
			sz=g.size();
			for(long long j=0;j<sz;j++){
				g.push_back({g[j].sum+a[i],a[i],g[j].sz+1});
			}
			g.push_back({a[i],a[i],1});
		}
		for(long long i=0;i<(long long)g.size();i++) if(g[i].sz>=3&&g[i].sum>g[i].mx*2) ans=(ans+1)%998244353;
		cout << ans;
	}else{
		long long gs=0,dq=n*(n-1)*(n-2),dq2=6;
		gs+=dq/dq2;
		for(long long k=4;k<=n;k++){
			dq*=(n-k+1);
			dq2*=k;
			gs=(gs+dq/dq2)%998244353;
		}
		cout << gs;
		return 0;
	}
	/*
	int zh,ans=0;
	for(int i=3;i<=n;i++){
		maxn=max(max(a[i],a[i-1]),a[i-2]);
		zh=a[i]+a[i-1]+a[i-2]+a[i-3];
		if(zh>2*maxn){
			cout << i-2 << " " << i << " " << zh << " " << maxn << '\n';
			ans++;
		}
		for(long long j=i+1;j<=n;j++){
			maxn=max(maxn,a[j]);
			zh+=a[j];
			
			if(zh>2*maxn){
				cout << i-2 << " " << j << " " << zh << " " << maxn << '\n';
			 	ans++;
			}
		}
	}
	cout << ans;*/
	return 0;
}
