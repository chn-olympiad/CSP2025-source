#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
const int M=(1<<20);
int n,k,a[N],ans,f[N],b[N],mx,cnt;
priority_queue<int>q[M];
bool flg=true;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	q[0].push(0);
	for(int i=1;i<=n;++i){
		int x=b[i]^k;
		if(q[x].size())f[i]=q[x].top()+1;
		mx=max(f[i],mx);
		f[i]=mx;
		q[b[i]].push(f[i]);
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}