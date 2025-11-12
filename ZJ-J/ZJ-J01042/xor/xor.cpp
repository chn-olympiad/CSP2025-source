#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
map<int,int>vis[N];
int a[N],pre[N],cnta,cntb;
int n,k,cnt[N],ans[N];
bool check(int x,int y){
	if(abs(pre[x]-pre[y])==k) return 1;
	else return 0;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	pre[1]=a[1];
	for(int i=2;i<=n;i++) pre[i]+=pre[i-1]^a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==1) cnta++;
		if(a[i]==0) cntb++;
	}
	if(cnta==n){
		cout<<n-1;
		return 0;
	}
	if(cntb==n){
		cout<<cnta;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(check(i,j)&&vis[i][j]==0ll){
				vis[i][j]=1ll,vis[j][i]=1ll;
				for(int k=i;k<=j;k++) cnt[k]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]+cnt[i-1]>ans[i]) ans[i]++;
		if(cnt[i+1]+cnt[i]>ans[i]) ans[i]++;
	}
	int maxn=-1;
	for(int i=1;i<=n;i++) maxn=max(maxn,ans[i]);
	cout<<maxn;
	return 0;
}
