#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k,ans,m;
int a[N],f[N];
struct E{
	int l,r;
}c[N],g[N];
int len;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=(f[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((f[j]^f[i-1])==k){
				c[++m].l=i;
				c[m].r=j;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(c[i].l>g[len].r){
			g[++len].l=c[i].l;
			g[len].r=c[i].r;
		}else{
			int l=1,r=len,ans=-1;
			while(l<=r){
				int mid=l+(r-l)/2;
				if(c[i].r<g[mid].r&&c[i].l>g[mid-1].r){
					ans=mid;
					r=mid-1;
				}else l=mid+1;
			}
			if(ans==-1) continue;
			g[ans].l=c[i].l;
			g[ans].r=c[i].r;
		}
	}
	cout<<len;
	return 0;
}

