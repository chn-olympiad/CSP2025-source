#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int s[N];
int n,k,a[N],cnt=0;
bool vis[N];
vector<int> g[(1<<20)];
void solve(int l,int r){
	if(l>r){
		return ;
	}
	if(l==r){
		if((s[l]^s[l-1])==k){
			cnt++;
			vis[l]=1;
		}
		return ;
	}
	int mid=l+((r-l)>>1);
	solve(l,mid);
	solve(mid+1,r);
	int x=mid,y=mid+1;
	if(vis[mid]||vis[mid+1])return ;
	while(!vis[x]&&x>=l)x--;
	x++;
	while(!vis[y]&&y<=r)y++;
	y--;
	for(int i=mid;i>=x;i--){
		for(int j:g[k^s[i-1]]){
			if(j<mid)continue;
			if(j>y)break;
			cnt++;
			for(int t=i;t<=j;t++)vis[t]=1;
			return ;
		}
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++)g[s[i]].push_back(i);
	solve(1,n);
	cout<<cnt;
	return 0;
}

