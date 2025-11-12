#include<bits/stdc++.h>
#define pb push_back

using namespace std;

const int N=5e5+10;
struct node{
	int l,r;
	bool operator<(node o)const{
		return r<o.r;
	}
}x[N];
int n,cnt,p[2000010];
long long arr[N],a[N],k;
vector<int> g[2000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		arr[i]=arr[i-1]^a[i];
		g[arr[i]].pb(i);
	}
	for(int i=1;i<=n;i++){
		int xr=-1;
		long long o=arr[i-1]^k;
		if(g[o].size()>p[o]) xr=g[(arr[i-1]^k)][p[o]];
		if(xr!=-1) x[++cnt]={i,xr};
		p[arr[i]]++;
	}
	sort(x+1,x+1+cnt);
	int xr=0,ans=0;
	for(int i=1;i<=cnt;i++){
		if(x[i].l>xr){
			xr=x[i].r;
			ans++;
		}
	}
	cout<<ans;
}
